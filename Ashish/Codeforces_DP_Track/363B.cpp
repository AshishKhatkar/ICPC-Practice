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
int h[300005];
int pref_sum[300005];
int main() {
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	pref_sum[0] = h[0];
	for(int i = 1; i < n; ++i) {
		pref_sum[i] = pref_sum[i - 1] + h[i];
	}
	int res = pref_sum[k - 1];
	int idx = 0;
	for(int i = 1; i <= n - k; ++i) {
		if(res > pref_sum[i + k - 1] - pref_sum[i - 1]) {
			res = pref_sum[i + k - 1] - pref_sum[i - 1];
			idx = i;
		}
	}
	cout << idx + 1 << endl;
	return 0;
}