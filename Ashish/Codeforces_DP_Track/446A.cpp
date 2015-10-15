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
int pref[100005], suff[100005];
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> ar[i];
	}
	int res = 1;
	pref[0] = 1;
	for(int i = 1; i < n; ++i) {
		if(ar[i] > ar[i - 1]) {
			pref[i] = pref[i - 1] + 1;
		} else {
			pref[i] = 1;
		}
		res = max(res, pref[i - 1] + 1);
	}
	suff[n - 1] = 1;
	for(int i = n - 2; i >= 0; --i) {
		if(ar[i] < ar[i + 1]) {
			suff[i] = suff[i + 1] + 1;
		} else {
			suff[i] = 1;
		}
		res = max(res, suff[i + 1] + 1);
	}
	for(int i = 1; i < n - 1; ++i) {
		if(ar[i + 1] - ar[i - 1] > 1) {
			res = max(res, pref[i - 1] + suff[i + 1] + 1);
		}
	}
	cout << res << endl;
	return 0;
}