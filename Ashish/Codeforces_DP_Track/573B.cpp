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
int ar[100005];
int dp[100005];
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> ar[i];
	}
	dp[0] = 0;
	for(int i = 1; i < n - 1; ++i) {
		dp[i] = min(dp[i - 1] + 1, ar[i] - 1);
	}
	dp[n - 1] = 0;
	for(int i = n - 2; i >= 1; --i) {
		dp[i] = min(dp[i], dp[i + 1] + 1);
	}
	int res = 0;
	for(int i = 0; i < n; ++i) {
		res = max(res, dp[i]);
	}
	cout << res + 1 << endl;
	return 0;
}