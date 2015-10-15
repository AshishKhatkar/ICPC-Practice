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
ll ar[100005], pref_sum[2][100005];
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> ar[i];
	}
	pref_sum[0][0] = ar[0];
	for(int i = 1; i < n; ++i) {
		pref_sum[0][i] = pref_sum[0][i - 1] + ar[i];
	}
	sort(ar, ar + n);
	pref_sum[1][0] = ar[0];
	for(int i = 1; i < n; ++i) {
		pref_sum[1][i] = pref_sum[1][i - 1] + ar[i];
	}
	int q;
	cin >> q;
	while(q--) {
		int type, l, r;
		cin >> type >> l >> r;
		type--;
		l--;
		r--;
		cout << pref_sum[type][r] - pref_sum[type][l - 1] << endl;
	}
	return 0;
}