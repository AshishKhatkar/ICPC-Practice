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
ll dp[1000005];
int main() {
	int k;
	cin >> k;
	string str;
	cin >> str;
	int len = str.length();
	ll res = 0;
	int cnt = 0;
	dp[0] = 1;
	for(int i = 0; i < len; ++i) {
		if(str[i] == '1') {
			cnt++;
		}
		if(cnt >= k) {
			res += dp[cnt - k];
		}
		dp[cnt]++;
	}
	cout << res << endl;
	return 0;
}