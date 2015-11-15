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
int par[100005], rnk[100005], res[100005];
set<int> qu[100005];
void init(int n, int m) {
	for(int i = 1; i <= n; ++i) {
		par[i] = i;
		rnk[i] = 1;
		qu[i].clear();
	}
	for(int i = 1; i <= m; ++i) {
		res[i] = INT_MAX;
	}
}
int Find(int nd) {
	if(par[nd] != nd) {
		par[nd] = Find(par[nd]);
	}
	return par[nd];
}
void Union(int nd1, int nd2, int val) {
	int x = Find(nd1);
	int y = Find(nd2);
	if(rnk[x] < rnk[y]) {
		par[x] = y;
		set<int>::iterator it;
		vector<int> v;
		for(it = qu[x].begin(); it != qu[x].end(); ++it) {
			if(qu[y].find((*it)) != qu[y].end() && (*it) > val) {
				res[(*it)] = val;
				v.push_back(*it);
			}
		}
		for(int i = 0; i < (int)(v.size()); ++i) {
			qu[x].erase(v[i]);
			qu[y].erase(v[i]);
		}
		for(it = qu[x].begin(); it != qu[x].end(); ++it) {
			qu[y].insert(*it);
		}
	} else if(rnk[x] > rnk[y]) {
		par[y] = x;
		set<int>::iterator it;
		vector<int> v;
		for(it = qu[y].begin(); it != qu[y].end(); ++it) {
			if(qu[x].find((*it)) != qu[x].end() && (*it) > val) {
				res[(*it)] = val;
				v.push_back(*it);
			}
		}
		for(int i = 0; i < (int)(v.size()); ++i) {
			qu[x].erase(v[i]);
			qu[y].erase(v[i]);
		}
		for(it = qu[y].begin(); it != qu[y].end(); ++it) {
			qu[x].insert(*it);
		}
	} else {
		par[y] = x;
		rnk[x]++;
		set<int>::iterator it;
		vector<int> v;
		for(it = qu[y].begin(); it != qu[y].end(); ++it) {
			if(qu[x].find((*it)) != qu[x].end() && (*it) > val) {
				res[(*it)] = val;
				v.push_back(*it);
			}
		}
		for(int i = 0; i < (int)(v.size()); ++i) {
			qu[x].erase(v[i]);
			qu[y].erase(v[i]);
		}
		for(it = qu[y].begin(); it != qu[y].end(); ++it) {
			qu[x].insert(*it);
		}
	}
}
int main() {
	int t;
	si(t);
	while(t--) {
		int n, m;
		si(n); si(m);
		init(n, m);
		int type, x, y;
		vector<pair<pair<int, int>, int > > v;
		vector<int> idx;
		for(int i = 1; i <= m; ++i) {
			si(type); si(x); si(y);
			if(type == 1) {
				v.push_back(make_pair(make_pair(x, y), i));
			} else {
				qu[x].insert(i);
				qu[y].insert(i);
				idx.push_back(i);
			}
		}
		int sz = (int)(v.size());
		for(int i = 0; i < sz; ++i) {
			int nd1 = Find(v[i].first.first);
			int nd2 = Find(v[i].first.second);
			if(nd1 != nd2) {
				Union(nd1, nd2, v[i].second);
			}
		}
		for(int i = 0; i < (int)(idx.size()); ++i) {
			if(res[idx[i]] == INT_MAX) {
				printf("-1\n");
			} else {
				pi(res[idx[i]]);
				pn;
			}
		}
	}
	return 0;
}