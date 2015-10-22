/*
Author : lifecodemohit
Problem : http://codeforces.com/problemset/problem/337/D
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

#define MOD 						1000000007
#define ll 							long long 
#define si(a)						scanf("%d", &a)
#define sn(a)						scanf("%I64d", &a)
#define pi(a)						printf("%d\n", a)
#define pn(a)						printf("%I64d\n", a)
#define ss(a)						scanf("%s", a)
#define rep(i, s, e)				for (int i = s; i <= e; i++)
#define rrep(i, s, e)				for (int i = s; i >= e; i--)
#define mem(arr, val)				memset(arr, val, sizeof(arr))
#define fill(arr, s, e, val)		for (int i = s; i <= e; i++)	arr[i] = val;
#define pb							push_back
#define mp							make_pair

int disdown[100010], disup[100010];
vector < int > adj[100010];
map < int , int > m1;
int root = 0;

void dfsdisdown(int cur, bool visit[]) {

	visit[cur] = true;
	if (m1[cur])
		disdown[cur] = 0;
	else
		disdown[cur] = -1;

	for (int i = 0; i < (int)adj[cur].size(); i++) {
		if (!visit[adj[cur][i]]) {
			dfsdisdown(adj[cur][i], visit);
			if (disdown[adj[cur][i]] > -1)
				disdown[cur] = max(disdown[cur], disdown[adj[cur][i]] + 1);
		}
	}
}

void dfsdisup(int cur, bool visit[]) {

	visit[cur] = true;
	
	vector < int > v2;
	int max1 = -1, max2 = -1;
	for (int i = 0; i < (int)adj[cur].size(); i++) {
		if (!visit[adj[cur][i]]) {
			v2.push_back(adj[cur][i]);
			if (disdown[adj[cur][i]] >= max1) {
				max2 = max1;
				max1 = disdown[adj[cur][i]];
			}
			else if (disdown[adj[cur][i]] >= max2)
				max2 = disdown[adj[cur][i]];
		}
	}
	for (int i = 0; i < (int)v2.size(); i++) {
		if (disdown[v2[i]] == max1)
			disup[v2[i]] = max2 + 2;
		else
			disup[v2[i]] = max1 + 2;	
		disup[v2[i]] = max(disup[v2[i]], disup[cur] + 1);
	}
	for (int i = 0; i < (int)adj[cur].size(); i++)
		if (!visit[adj[cur][i]])
			dfsdisup(adj[cur][i], visit);
}

int main()
{
	int n, m, d, p;
	si(n);	si(m);	si(d);
	rep(i, 0, m-1) {
		si(p);
		p--;
		m1[p] = 1;
	}
	rep(i, 0, n-2) {
		int x, y;
		si(x);	si(y);
		x--;	y--;
		adj[x].pb(y);	adj[y].pb(x);
	}

	bool visit[100010];

	mem(visit, false);
	dfsdisdown(0, visit);

	mem(visit, false);
	disup[0] = (m1[p] ? 0 : -1);
	dfsdisup(0, visit);

	int cnt = 0;
	disup[0] = 0;
	for (int i = 0; i < n; i++) {
		cout << disup[i] << " " << disdown[i] << endl;
		if (disdown[i] <= d && disup[i] <= d)
			cnt++;
	}

	pi(cnt);
	return 0;
}