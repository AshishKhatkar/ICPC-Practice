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
int dp[205][1000005];
int main() {
	int t;
	si(t);
	while(t--) {
		ll a, b, n, p;
		sl(a); sl(b); sl(n); sl(p);
		for(int i = 0; i < p; ++i) {
			for(int j = 0; j < n; ++j) {
				dp[i][j] = 0;
			}
		}
		vector<int> v;
		for(int i = 0; i < n; ++i) {
			a *= 10ull;
			v.push_back(a / b);
			a %= b;
		}
		ll res = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < p; ++j) {
				dp[(j * 10 + v[i]) % p][i] += dp[j][i - 1];
			}
			dp[v[i] % p][i]++;
			res += dp[0][i];
		}
		pl(res);
		pn;
	}
	return 0;
}