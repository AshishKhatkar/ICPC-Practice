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
int dp[4005];
int solve(int n, int a, int b, int c) {
	if(n == 0) {
		return 0;
	} else if(n < min(a, min(b, c))) {
		return INT_MIN;
	}
	if(dp[n] != -1) {
		return dp[n];
	}
	dp[n] = INT_MIN;
	if(n >= a) {
		dp[n] = max(dp[n], solve(n - a, a, b, c) + 1);
	}
	if(n >= b) {
		dp[n] = max(dp[n], solve(n - b, a, b, c) + 1);
	}
	if(n >= c) {
		dp[n] = max(dp[n], solve(n - c, a, b, c) + 1);
	}
	return dp[n];
}
int main() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	memset(dp, -1, sizeof(dp));
	cout << solve(n, a, b, c) << endl;
	return 0;
}