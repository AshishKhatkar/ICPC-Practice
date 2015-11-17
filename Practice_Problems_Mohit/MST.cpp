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

int par[100010], rnk[100010];

vector < pair < int , pair < int, int > > > edge;
vector < pair < int , int > > mst;

int Find(int x) {
	if (x != par[x])
		par[x] = Find(par[x]);
	return par[x];
} 

void Union(int x, int y) {
	if (rnk[x] < rnk[y]) 
		par[y] = x;
	else if (rnk[x] > rnk[y])
		par[x] = y;
	else {
		par[y] = x;
		rnk[x]++;
	}
}

int main()
{
	edge.clear();
	mst.clear();

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		par[i] = i;
		rnk[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		x--; y--;
		edge.push_back(make_pair(w, make_pair(x, y)));
	}

	sort(edge.begin(), edge.end());

	int cnt = 0;
	int top = 0;
	int sz = edge.size();
	long long ans = 0;

	while (cnt < n-1) {
		pair < int , int > p = edge[top++].second;
		int x = Find(p.first);
		int y = Find(p.second);
		if (x != y) {
			cnt++;
			Union(x, y);
			mst.push_back(p);
			ans += edge[top-1].first;
		}
	}

	cout << ans << endl;
	return 0;
}