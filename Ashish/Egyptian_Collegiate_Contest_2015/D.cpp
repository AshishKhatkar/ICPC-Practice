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
vector<pair<int, ll> > adj[100005];
ll tmw[100005];
vector<ll> v;
void dfs(int nd) {
	if(nd != 1 && (int)(adj[nd].size()) == 0) {
		v.push_back(tmw[nd]);
		return;
	}
	ll minx = LONG_LONG_MAX;
	for(int i = 0; i < (int)(adj[nd].size()); ++i) {
		ll to_dist = adj[nd][i].second;
		minx = min(minx, to_dist);
	}
	for(int i = 0; i < (int)(adj[nd].size()); ++i) {
		int to = adj[nd][i].first;
		ll to_dest = adj[nd][i].second;
		tmw[to] = tmw[nd] + minx + (to_dest - minx) * 2;
		dfs(to);
	}
}
int main() {
	int t;
	si(t);
	while(t--) {
		int n;
		si(n);
		for(int i = 1; i <= n; ++i) {
			adj[i].clear();
		}
		int x;
		ll y;
		for(int i = 2; i <= n; ++i) {
			si(x); sl(y);
			adj[x].push_back(make_pair(i, y));
		}
		v.clear();
		tmw[1] = 0;
		dfs(1);
		sort(v.begin(), v.end());
		int m;
		si(m);
		ll qt;
		// for(int i = 1; i <= n; ++i) {
		// 	cout << tmw[i] << " ";
		// }
		// cout << endl;
		while(m--) {
			sl(qt);
			int res = upper_bound(v.begin(), v.end(), qt) - v.begin();
			pi(res);
			pn;
		}
	}
	return 0;
}