/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll				long long int
#define MOD				1000000007
#define rep(i, a, b)	for(i=a; i<=b; ++i)
#define rrep(i, a, b)	for(i=a; i>=b; --i)
#define si(a)			scanf("%d", &a)
#define sl(a)			scanf("%lld", &a)
#define pi(a)			printf("%d", a)
#define pl(a)			printf("%lld", a)
#define pn 				printf("\n")
ll pow_mod(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b & 1)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}
vector<pair<int, ll > > adj[100005];
ll dist[100005];
bool visited[100005];
int par[100005];
int paths[100005];
void Dijkstra(int src, int dest, int n) {
	for(int i = 0; i < n; ++i) {
		dist[i] = INT_MAX;
		visited[i] = false;
		paths[i] = 0;
	}
	priority_queue<pair<ll, int> > pq;
	pq.push(make_pair(0, src));
	dist[src] = 0;
	par[src] = -1;
	paths[src] = 1;
	while(!pq.empty()) {
		pair<ll, int> tp = pq.top();
		pq.pop();
		int local_src = tp.second;
		ll local_dist = -tp.first;
		if(!visited[local_src]) {
			visited[local_src] = true;
			for(int i = 0; i < (int)(adj[local_src].size()); ++i) {
				int to_nd = adj[local_src][i].first;
				ll to_cst = adj[local_src][i].second;
				if(dist[to_nd] > to_cst + local_dist) {
					dist[to_nd] = to_cst + local_dist;
					pq.push(make_pair(-1 * dist[to_nd], to_nd));
					par[to_nd] = local_src;
					paths[to_nd] = paths[local_src];
				} else if(dist[to_nd] == to_cst + local_dist && par[to_nd] != local_src) {
					paths[to_nd] += paths[local_src];
				}
			}
		}
	}
	// cout << dist[dest] << endl;
	cout << paths[dest] << endl;
}
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		adj[i].clear();
	}
	int src, dest;
	ll cst;
	for(int i = 0; i < m; ++i) {
		cin >> src >> dest >> cst;
		adj[src].push_back(make_pair(dest, cst));
		// adj[dest].push_back(make_pair(src, cst));
	}
	cin >> src >> dest;
	Dijkstra(src, dest, n);
	return 0;
}