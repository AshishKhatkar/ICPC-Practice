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
int ar[50005][5];
int dp[50005][5];
int main() {
	int m, n;
	cin >> m >> n;
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> ar[i][j];
		}
	}
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			if(i) {
				dp[i][j] = dp[i - 1][j];
			}
			if(j) {
				dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			}
			dp[i][j] += ar[i][j];
		}
		cout << dp[i][n - 1] << " ";
	}
	cout << endl;
	return 0;
}