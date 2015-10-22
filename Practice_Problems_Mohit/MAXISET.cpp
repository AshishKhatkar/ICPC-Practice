/*
Author : lifecodemohit
Problem : http://www.spoj.com/problems/MAXISET/en/
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
// #include <bits/stdc++.h>

using namespace std;

#define MOD 						1000000007
#define ll 							long long 
#define si(a)						scanf("%d", &a)
#define sn(a)						scanf("%lld", &a)
#define pi(a)						printf("%d\n", a)
#define pn(a)						printf("%lld\n", a)
#define ss(a)						scanf("%s", a)
#define rep(i, s, e)				for (int i = s; i <= e; i++)
#define rrep(i, s, e)				for (int i = s; i >= e; i--)
#define mem(arr, val)				memset(arr, val, sizeof(arr))
#define fill(arr, s, e, val)		for (int i = s; i <= e; i++)	arr[i] = val;
#define pb							push_back
#define mp							make_pair

int wt[41];
int arr[41][41];
int res1[10000010], res2[10000010];
int power[25];
int v[41];
int set1[41], set2[41];
int rmap1[41], rmap2[41];

bool bfs(int mark1[], int A[][41], int sz) {
	bool flag = true;
	int i;
	for (i = 0; i < sz; i++) {
		if (mark1[i]) 
			break;
	}
	if (i < sz) {
		bool visit[41];
		mem(visit, false);
		int front = 0, rear = 0;
		int que[41];
		que[front] = i;
		visit[i] = true;
		while (front <= rear) {
			int top = que[front];
			for (int i = 0; i < sz; i++) {
				if ((A[top][i] == 1) && (!visit[i])) {
					rear++;
					que[rear] = i;
					visit[i] = true;
					if (mark1[top] && mark1[i]) {
						flag = false;
						break;
					}
				}
			}
			front++;
			if (!flag)
				break;
		}
	}
	return flag;
}
void solve(int v[], int s) {
	int s1 = floor(s/2.0);
	int s2 = s - s1;
	
	int result = 0;
	for (int i = 0; i < floor(s/2.0); i++) {
		set1[i] = v[i];
		rmap1[v[i]] = i;
	}
	for (int i = floor(s/2.0), j = 0; i < s; i++, j++) {
		set2[j] = v[i];
		rmap2[v[i]] = j;
	}
	int A1[41][41], A2[41][41];
	mem(A1, 0);
	mem(A2, 0);
	for (int i = 0; i < s1; i++) {
		for (int j = 0; j < s1; j++) {
			if (arr[set1[i]][set1[j]] == 1) {
				A1[i][j] = 1;
				A1[j][i] = 1;
			}
		}
	}
	for (int i = 0; i < s2; i++) {
		for (int j = 0; j < s2; j++) {
			if (arr[set2[i]][set2[j]] == 1) {
				A2[i][j] = 1;
				A2[j][i] = 1;
			}
		}
	}
	for (int i = 0; i < power[s1]; i++) {
		int ans = 0;
		int mark1[41];
		mem(mark1, 0);
		for (int j = 0; j < s1; j++) {
			if (i & (1 << j))
				mark1[j] = 1;
		}
		if (bfs(mark1, A1, s1)) {
			for (int j = 0; j < s1; j++) {
				bool flag = false;
				if (i & (1 << j)) {
					ans = ans + wt[set1[j]];
				}
			}
		}
		res1[i] = ans;
		result = max(result, ans);
	}
	for (int i = 0; i < power[s2]; i++) {
		int ans = 0;
		int mark2[41];
		mem(mark2, 0);
		for (int j = 0; j < s2; j++) {
			if (i & (1 << j))
				mark2[j] = 1;
		}
		if (bfs(mark2, A2, s2)) {
			for (int j = 0; j < s2; j++) {
				bool flag = false;
				if (i & (1 << j)) {
					ans = ans + wt[set2[j]];
				}
			}
		}
		res2[i] = ans;
		result = max(result, ans);
	}
	int A3[41][41];
	mem(A3, 0);
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			if (arr[v[i]][v[j]] == 1) {
				A3[i][j] = 1;
				A3[j][i] = 1;
			}
		}
	}
	int set[41];
	int rmap[41];
	mem(set, 0);
	for (int i = s1; i < s; i++) {
		set[i] = 2;
		rmap[i] = i - s1;
	}
	for (int i = 0; i < power[s1]; i++) {
		int val = power[s2] - 1;
		if (res1[i] != 0) {
			int pos;
			for (int j = 0; j < s1; j++) {
				if (i & (1 << j)) {
					pos = j;
					set[j] = 1;
				}
			}
			int front = 0, rear = 0;
			int que[41];
			bool visit[41];
			mem(visit, false);
			que[front] = pos;
			visit[pos] = true;
			while (front <= rear) {
				int top = que[front];
				for (int i1 = 0; i1 < s; i1++) {
					if ((A3[top][i1] == 1) && (!visit[i1])) {
						rear++;
						que[rear] = i1;
						visit[i1] = true;
						if ((set[top] == 1) && (set[i1] == 2) && (val & (1 << rmap[i1]))) {
							val = val - (1 << rmap[i1]);
						}
						else if ((set[top] == 2) && (set[i1] == 1) && (val & (1 << rmap[top]))) {
							val = val - (1 << rmap[top]);
						}
					}
				}
				front++;
			}
			for (int j = 0; j < s1; j++) {
				if (i & (1 << j)) {
					pos = j;
					set[j] = 0;
				}
			}
			result = max(result, res1[i] + res2[val]);
		}
	}
	printf("%d\n", result);
}

int main()
{
	power[0] = 1;
	for (int i = 1; i <= 22; i++)
		power[i] = power[i-1]*2;

	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m; 
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d", &wt[i]);
			for (int j = 0; j < n; j++)
				arr[i][j] = 0;
		}
		for (int i = 0; i < m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			arr[x][y] = 1;
			arr[y][x] = 1;
		}
		int q;
		scanf("%d", &q);
		while (q--) {
			int s;
			scanf("%d", &s);
			for (int i = 0; i < s; i++)
				scanf("%d", &v[i]);
			solve(v, s);
		}
		printf("\n");
	}
	return 0;
}