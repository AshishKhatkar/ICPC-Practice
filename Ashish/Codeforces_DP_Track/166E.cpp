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
int dp[10000005][4];
int main() {
	int n;
	cin >> n;
	dp[0][0] = 0; //a
	dp[0][1] = 0; //b
	dp[0][2] = 0; //c
	dp[0][3] = 1; //d
	for(int i = 1; i <= n; ++i) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % MOD;
		dp[i][0] = (dp[i][0] + dp[i - 1][3]) % MOD;

		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
		dp[i][1] = (dp[i][1] + dp[i - 1][3]) % MOD;

		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
		dp[i][2] = (dp[i][2] + dp[i - 1][3]) % MOD;

		dp[i][3] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
		dp[i][3] = (dp[i][3] + dp[i - 1][2]) % MOD;
	}
	cout << dp[n][3] << endl;
	return 0;
}