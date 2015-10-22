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
ll ar[5005], pref_sum[5005];
ll dp[5005][5005];
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < n; ++i) {
		cin >> ar[i];
	}
	pref_sum[0] = ar[0];
	for(int i = 1; i < n; ++i) {
		pref_sum[i] = pref_sum[i - 1] + ar[i];
	}
	dp[m - 1][1] = pref_sum[m - 1];
	for(int i = m; i < n; ++i) {
		for(int j = 1; j <= k; ++j) {
			dp[i][j] = max(dp[i - 1][j], dp[i - m][j - 1] + pref_sum[i] - pref_sum[i - m]);
		}
	}
	cout << dp[n - 1][k] << endl;
	return 0;
}