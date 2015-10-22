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
int dp[105][2];
int main() {
	int n, k, d;
	cin >> n >> k >> d;
	dp[0][0] = 1;
	dp[0][1] = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= k; ++j) {
			if(j <= i) {
				if(j < d) {
					dp[i][0] = (dp[i][0] + dp[i - j][0]) % MOD;
					dp[i][1] = (dp[i][1] + dp[i - j][1]) % MOD;
				} else {
					dp[i][1] = (dp[i][1] + dp[i - j][0]) % MOD;
					dp[i][1] = (dp[i][1] + dp[i - j][1]) % MOD;
				}
			}
		}
	}
	cout << dp[n][1] << endl;
	return 0;
}