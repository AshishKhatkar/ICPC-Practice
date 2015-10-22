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
ll ar[500005];
int main() {
	int n;
	cin >> n;
	ll sm = 0;
	for(int i = 0; i < n; ++i) {
		cin >> ar[i];
		sm += ar[i];
	}
	if(sm % 3) {
		cout << "0\n";
	} else {
		vector<int> v1, v2;
		ll targ_val = sm / 3;
		sm = 0;
		for(int i = 0; i < n - 1; ++i) {
			sm += ar[i];
			if(sm == targ_val) {
				v1.push_back(i);
			}
			if(sm == 2 * targ_val) {
				v2.push_back(i);
			}
		}
		int idx = 0, idx1 = 0;
		int sz1 = v1.size();
		int sz2 = v2.size();
		ll res = 0;
		while(idx < sz1 && idx1 < sz2) {
			if(v1[idx] < v2[idx1]) {
				res += (int)(v2.size()) - idx1;
				idx++;
			} else {
				idx1++;
			}
		}
		cout << res << endl;
	}
	return 0;
}