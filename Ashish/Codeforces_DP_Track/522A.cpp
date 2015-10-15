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
map<string, int> mp;
vector<int> adj[205];
bool visited[205];
int dfs(int nd) {
	visited[nd] = true;
	int res = 0;
	for(int i = 0; i < (int)(adj[nd].size()); ++i) {
		int to = adj[nd][i];
		if(!visited[to]) {
			res = max(res, dfs(to));
		}
	}
	return res + 1;
}
string convert_str(string str) {
	string res = "";
	for(int i = 0; i < (int)(str.length()); ++i) {
		if(str[i] >= 'A' && str[i] <= 'Z') {
			res = res + (char)(str[i] - 'A' + 'a');
		} else {
			res = res + str[i];
		}
	}
	return res;
}
int main() {
	int n, idx = 1;
	cin >> n;
	mp["polycarp"] = 0;
	string str1, str2, tmp;
	for(int i = 0; i < n; ++i) {
		cin >> str1 >> tmp >> str2;
		str1 = convert_str(str1);
		str2 = convert_str(str2);
		if(mp.find(str1) == mp.end()) {
			mp[str1] = idx;
			idx++;
		}
		adj[mp[str2]].push_back(mp[str1]);
	}
	cout << dfs(0) << endl;
	return 0;
}