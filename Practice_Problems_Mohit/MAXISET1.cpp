/*
Author : lifecodemohit
*/

#ifdef __APPLE__

    #include <cassert>
    #include <iostream>
    #include <iomanip>
    #include <ctime>
    #include <cstdio>
    #include <vector>
    #include <algorithm>
    #include <utility>
    #include <queue>
    #include <stack>
    #include <string>
    #include <cstring>
    #include <sstream>
    #include <map>
    #include <set>
    #include <unordered_map>
    #include <unordered_set>

#else

    #include <bits/stdc++.h>

#endif  

using namespace std;

vector < int > adj[41];

int mis(vector < pair < int, int > > v2, int mark[]) {
	if ((int)v2.size() == 0)
		return 0;
	int mini = INT_MAX;
	int ver;
	for (int i = 0; i < (int)v2.size(); i++) {
		if (v2[i].second < mini) {
			mini = v2[i].second;
			ver = v2[i].first;
		}
	}
	for (int i = 0; i < )
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		int w[n];
		bool mark[n];
		for (int i = 0; i < n; i++) {
			scanf("%d", &w[i]);
			adj[i].clear();
		}
		for (int i = 0; i < m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		scanf("%d", &q);
		while (q--) {
			int s;
			scanf("%d", &s);
			int v[s];
			memset(mark, false, sizeof(mark));
			for (int i = 0; i < s; i++) {
				scanf("%d", &v[i]);
				mark[v] = true;
			}
			vector < pair < int, int > > v1;
			for (int i = 0; i < s; i++) {
				int cnt = 0;
				for (int j = 0; j < (int)adj[v[i]].size(); j++) {
					if (mark[adj[v[i]][j]])
						cnt++;
				}
				v1.push(make_pair(v[i], cnt));
			}
		}
	}
	return 0;
}