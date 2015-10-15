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
vector<int> quasi_no;
int dp[1000005];
int solve(int n) {
	if(n < 0) {
		return 1000000;
	} else if(n == 0) {
		return 0;
	}
	if(dp[n] != -1) {
		return dp[n];
	}
	dp[n] = INT_MAX;
	for(int i = 0; i < (int)(quasi_no.size()); ++i) {
		dp[n] = min(dp[n], 1 + solve(n - quasi_no[i]));
	}
	return dp[n];
}
void gen_quasi(int n) {
	if(n > 1000000) {
		return;
	}
	quasi_no.push_back(n * 10);
	gen_quasi(n * 10);
	quasi_no.push_back(n * 10 + 1);
	gen_quasi(n * 10 + 1);
}
int main() {
	quasi_no.push_back(1);
	gen_quasi(1);
	sort(quasi_no.begin(), quasi_no.end());
	int n;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	cout << solve(n) << endl;
	while(n) {
		int res = dp[n];
		for(int i = 0; i < (int)(quasi_no.size()); ++i) {
			if(n - quasi_no[i] >= 0) {
				if(res == 1 + dp[n - quasi_no[i]]) {
					cout << quasi_no[i] << " ";
					n -= quasi_no[i];
					break;
				}
			}
		}
	}
	cout << endl;
	return 0;
}