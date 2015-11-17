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
vector<int> adj[105][105];
set<int> cols;
vector<int> vec;
bool visited[105];
void dfs(int nd, int col) {
	visited[nd] = true;
	for(int i = 0; i < (int)(adj[col][nd].size()); ++i) {
		int to = adj[col][nd][i];
		if(!visited[to]) {
			dfs(to, col);
		}
	}
}
int main() {
	int n, m, u, v, c;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		cin >> u >> v >> c;
		adj[c][u].push_back(v);
		adj[c][v].push_back(u);
		cols.insert(c);
	}
	set<int>::iterator it;
	for(it = cols.begin(); it != cols.end(); ++it) {
		vec.push_back((*it));
	}
	m = vec.size();
	int q;
	cin >> q;
	while(q--) {
		cin >> u >> v;
		int res = 0;
		for(int i = 0; i < m; ++i) {
			memset(visited, false, sizeof(visited));
			dfs(u, vec[i]);
			if(visited[v]) {
				res++;
			}
		}
		cout << res << endl;
	}
	return 0;
}