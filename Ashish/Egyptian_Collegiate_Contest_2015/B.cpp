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
char res[105];
set<char> s[105];
int main() {
	int t;
	cin >> t;
	while(t--) {
		int q, m;
		cin >> q >> m;
		for(int i = 0; i < q; ++i) {
			res[i] = '?';
			s[i].clear();
		}
		for(int i = 0; i < m; ++i) {
			char ch1, ch2;
			for(int j = 0; j < q; ++j) {
				cin >> ch1 >> ch2;
				if(ch2 == 'T') {
					res[j] = ch1;
				} else {
					s[j].insert(ch1);
				}
			}
		}
		for(int i = 0; i < q; ++i) {
			if(res[i] != '?') {
				cout << res[i];
			} else {
				if((int)(s[i].size()) != 3) {
					cout << res[i];
				} else {
					string tmp = "ABCD";
					if(s[i].find(tmp[0]) == s[i].end()) {
						cout << tmp[0];
					} else if(s[i].find(tmp[1]) == s[i].end()) {
						cout << tmp[1];
					} else if(s[i].find(tmp[2]) == s[i].end()) {
						cout << tmp[2];
					} else if(s[i].find(tmp[3]) == s[i].end()) {
						cout << tmp[3];
					}
				}
			}
			if(i == q - 1) {
				cout << endl;
			} else {
				cout << " ";
			}
		}
	}
	return 0;
}