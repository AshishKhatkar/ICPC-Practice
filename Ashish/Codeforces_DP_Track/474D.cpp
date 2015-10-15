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
ll dp[100005];
int main() {
	int t, k;
	cin >> t >> k;
	for(int i = 0; i < k; ++i) {
		dp[i] = 1;
	}
	for(int i = k; i <= 100000; ++i) {
		dp[i] = (dp[i - k] + dp[i - 1]) % MOD;
	}
	for(int i = 1; i <= 100000; ++i) {
		dp[i] = (dp[i - 1] + dp[i]) % MOD;
	}
	while(t--) {
		int a, b;
		cin >> a >> b;
		cout << (dp[b] - dp[a - 1] + MOD) % MOD << endl;
	}
	return 0;
}