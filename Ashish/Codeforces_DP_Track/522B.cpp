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
pair<int, int> ar[200005];
int pref_max[200005], suff_max[200005];
int main() {
	int n;
	cin >> n;
	int sm = 0;
	for(int i = 0; i < n; ++i) {
		cin >> ar[i].first >> ar[i].second;
		sm += ar[i].first;
	}
	pref_max[0] = ar[0].second;
	for(int i = 1; i < n; ++i) {
		pref_max[i] = max(pref_max[i - 1], ar[i].second);
	}
	suff_max[n - 1] = ar[n - 1].second;
	for(int i = n - 2; i >= 0; --i) {
		suff_max[i] = max(suff_max[i + 1], ar[i].second);
	}
	for(int i = 0; i < n; ++i) {
		ll res = sm - ar[i].first;
		if(i == 0) {
			res = res * suff_max[i + 1];
		} else if(i == n - 1) {
			res = res * pref_max[i - 1];
		} else {
			res = res * max(pref_max[i - 1], suff_max[i + 1]);
		}
		cout << res << " ";
	}
	cout << endl;
	return 0;
}