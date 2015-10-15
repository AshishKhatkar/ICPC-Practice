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
int dp[2005][2005];
int main() {
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= k; ++i) {
		dp[1][i] = 1;
	}
	for(int i = 1; i <= n; ++i) {
		dp[i][1] = 1;
	}
	for(int i = 2; i <= n; ++i) {
		for(int j = 2; j <= k; ++j) {
			for(int l = 1; l * l <= i; ++l) {
				if(i % l == 0) {
					dp[i][j] += dp[l][j - 1];
					dp[i][j] %= MOD;
					if(i / l != l) {
						dp[i][j] += dp[i / l][j - 1];
						dp[i][j] %= MOD;
					}
				}
			}
		}
	}
	ll res = 0;
	for(int i = 1; i <= n; ++i) {
		res = (res + dp[i][k]) % MOD;
	}
	cout << res << endl;
	return 0;
}