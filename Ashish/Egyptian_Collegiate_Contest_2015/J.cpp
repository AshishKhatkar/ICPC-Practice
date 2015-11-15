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
char ar[26][26];
vector<int> adj[500005];
int res[500005];
bool dfs(int nd, bool flag) {
	if(adj[nd].size() == 0) {
		return res[nd];
	}
	bool ans = flag;
	for(int i = 0; i < (int)(adj[nd].size()); ++i) {
		int to = adj[nd][i];
		if(flag) {
			ans &= dfs(to, !flag);
		} else {
			ans |= dfs(to, !flag);
		}
	}
	return ans;
}
int main() {
	int t;
	si(t);
	while(t--) {
		for(int i = 1; i <= 500000; ++i) {
			adj[i].clear();
			res[i] = 0;
		}
		for(int i = 0; i < 26; ++i) {
			for(int j = 0; j < 26; ++j) {
				cin >> ar[i][j];
			}
		}
		string str;
		cin >> str;
		queue<pair<string, int> > q;
		q.push(make_pair(str, 1));
		int idx = 2;
		while(!q.empty()) {
			pair<string, int> p = q.front();
			q.pop();
			string st = p.first;
			int nd = p.second;
			int len = st.length();
			string tmp = "";
			for(int i = len - 1; i > 0; i -= 2) {
				tmp = ar[st[i] - 'a'][st[i - 1] - 'a'] + tmp;
			}
			if(len & 1) {
				tmp = st[0] + tmp;
			}
			if((int)(tmp.length()) == 1) {
				if(tmp[0] == 'a' || tmp[0] == 'e' || tmp[0] == 'i' || tmp[0] == 'o' || tmp[0] == 'u') {
					res[idx] = 1;
				} else {
					res[idx] = 0;
				}
				adj[nd].push_back(idx);
			} else {
				adj[nd].push_back(idx);
				q.push(make_pair(tmp, idx));
			}
			idx++;
			tmp = "";
			for(int i = 0; i < len - 1; i += 2) {
				tmp = tmp + ar[st[i] - 'a'][st[i + 1] - 'a'];
			}
			if(len & 1) {
				tmp = tmp + st[len - 1];
			}
			if((int)(tmp.length()) == 1) {
				if(tmp[0] == 'a' || tmp[0] == 'e' || tmp[0] == 'i' || tmp[0] == 'o' || tmp[0] == 'u') {
					res[idx] = 1;
				} else {
					res[idx] = 0;
				}
				adj[nd].push_back(idx);
			} else {
				adj[nd].push_back(idx);
				q.push(make_pair(tmp, idx));
			}
			idx++;
		}
		if(dfs(1, 0)) {
			printf("Salah\n");
		} else {
			printf("Marzo\n");
		}
	}
	return 0;
}