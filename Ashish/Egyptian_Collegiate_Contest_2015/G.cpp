/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll				long long int
#define vi				vector<int>
#define vl				vector<ll>
#define	pii				pair<int,int>
#define pil				pair<int, ll>
#define pll				pair<ll, ll>
#define pli 			pair<ll, int>
#define pb(v, a)		v.push_back(a)
#define mp(a, b)		make_pair(a, b)
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
vector<pair<int, pair<ll, ll> > > adj[100005];
ll dist[100005];
bool visited[100005];
bool Dijkstra(int src, int dest, int n, ll wis, ll k) {
	for(int i = 1; i <= n; ++i) {
		dist[i] = INT_MAX;
		visited[i] = false;
	}
	priority_queue<pair<ll, int> > pq;
	pq.push(make_pair(0, src));
	dist[src] = 0;
	while(!pq.empty()) {
		pair<ll, int> tp = pq.top();
		pq.pop();
		int local_src = tp.second;
		ll local_dist = -tp.first;
		if(!visited[local_src]) {
			visited[local_src] = true;
			for(int i = 0; i < (int)(adj[local_src].size()); ++i) {
				int to_nd = adj[local_src][i].first;
				ll to_cst = adj[local_src][i].second.first;
				ll to_wis = adj[local_src][i].second.second;
				if(dist[to_nd] > to_cst + local_dist && wis >= to_wis) {
					dist[to_nd] = to_cst + local_dist;
					pq.push(make_pair(-1 * dist[to_nd], to_nd));
				}
			}
		}
	}
	if(dist[dest] < k) {
		return true;
	} else {
		return false;
	}
}
int main() {
	int t;
	si(t);
	while(t--) {
		int n, m;
		ll k;
		si(n); si(m); sl(k);
		for(int i = 1; i <= n; ++i) {
			adj[i].clear();
		}
		int src, dest;
		ll cst, wis;
		ll maxx = 0;
		for(int i = 0; i < m; ++i) {
			si(src); si(dest); sl(cst); sl(wis);
			adj[src].push_back(make_pair(dest, make_pair(cst, wis)));
			adj[dest].push_back(make_pair(src, make_pair(cst, wis)));
			maxx = max(maxx, wis);
		}
		ll low = 0, high = maxx;
		int ans = -1;
		while(low <= high) {
			ll mid = (low + high) >> 1;
			if(Dijkstra(1, n, n, mid, k)) {
				high = mid - 1;
				ans = mid;
			} else {
				low = mid + 1;
			}
		}
		pi(ans);
		pn;
	}
	return 0;
}