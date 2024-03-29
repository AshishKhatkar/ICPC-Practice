/*
Author : lifecodemohit
Problem : https://www.codechef.com/problems/MULTQ3
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

using namespace std;

#define MOD 			1000000007
#define ll 				long long 
#define si(a)			scanf("%d", &a)
#define sn(a)			scanf("%lld", &a)
#define pi(a)			printf("%d\n", a)
#define pn(a)			printf("%lld\n", a)
#define ss(a)			scanf("%s", a)
#define rep(i, s, e)	for (i = s; i <= e; i++)
#define rrep(i, s, e)	for (i = s; i >= e; i--)
#define mem(arr, val)	memset(arr, val, sizeof(arr))
#define pb				push_back
#define mp				make_pair

int tree[400010][3];
int lazy[400010];

void buildseg(int idx, int l, int r) {
	if (l == r) {
		tree[idx][0] = 1;
		tree[idx][1] = 0;
		tree[idx][2] = 0;
		return ;
	}
	int mid = ((l + r) >> 1);
	buildseg((idx << 1), l, mid);
	buildseg((idx << 1) +1, mid+1, r);
	tree[idx][0] = tree[(idx << 1)][0] + tree[(idx << 1)+1][0];
	tree[idx][1] = tree[(idx << 1)][1] + tree[(idx << 1)+1][1];
	tree[idx][2] = tree[(idx << 1)][2] + tree[(idx << 1)+1][2];
}

void rotate1(int idx) {
	int tempa = tree[idx][0];
	int tempb = tree[idx][1];
	int tempc = tree[idx][2];
	tree[idx][0] = tempc;
	tree[idx][1] = tempa;
	tree[idx][2] = tempb;
}

void rotate2(int idx) {
	int tempa = tree[idx][0];
	int tempb = tree[idx][1];
	int tempc = tree[idx][2];
	tree[idx][0] = tempb;
	tree[idx][1] = tempc;
	tree[idx][2] = tempa;
}

void update(int idx, int l, int r, int x, int y) {

	lazy[idx] = lazy[idx] % 3;
	if (lazy[idx] != 0) {
		if (l != r) {
			lazy[(idx << 1)] += lazy[idx];
			lazy[(idx << 1) +1] += lazy[idx];
		}
		if (lazy[idx] == 1)
			rotate1(idx);
		else if (lazy[idx] == 2)
			rotate2(idx);
		lazy[idx] = 0;
	}

	if (x > y || y < l || x > r)	return ;

	if (x <= l && r <= y) {
		rotate1(idx);
		if (l != r) {
			lazy[(idx << 1)] += 1;
			lazy[(idx << 1) +1] += 1;
		}
		return ;
	}

	int mid = ((l + r) >> 1);
	update((idx << 1), l, mid, x, y);
	update((idx << 1) + 1, mid+1, r, x, y);
	tree[idx][0] = tree[(idx << 1)][0] + tree[(idx << 1) +1][0];
	tree[idx][1] = tree[(idx << 1)][1] + tree[(idx << 1) +1][1];
	tree[idx][2] = tree[(idx << 1)][2] + tree[(idx << 1) +1][2];
	lazy[idx] = lazy[(idx << 1)] + lazy[(idx << 1) +1];
}

int query(int idx, int l, int r, int x, int y) {

	lazy[idx] = lazy[idx] % 3;
	if (lazy[idx] != 0) {
		if (l != r) {
			lazy[(idx << 1)] += lazy[idx];
			lazy[(idx << 1) +1] += lazy[idx];
		}
		if (lazy[idx] == 1)
			rotate1(idx);
		else if (lazy[idx] == 2)
			rotate2(idx);
		lazy[idx] = 0;
	}

	if (x > y || y < l || x > r)	return 0;

	if (x <= l && r <= y)	return tree[idx][0];

	int mid = ((l + r) >> 1);
	int left = query((idx << 1), l, mid, x, y);
	int right = query((idx << 1) +1, mid+1, r, x, y);
	return left + right;
}

int main()
{
	int n, q;
	si(n);	si(q);
	buildseg(1, 0, n-1);
	mem(lazy, 0);
	while (q--) {
		int type, x, y;
		si(type); si(x); si(y);
		if (type == 0)	update(1, 0, n-1, x, y);
		else	pi(query(1, 0, n-1, x, y));
	}
	return 0;
}