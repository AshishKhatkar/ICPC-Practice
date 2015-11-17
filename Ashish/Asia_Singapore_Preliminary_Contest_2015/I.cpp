/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll				long long int
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
int pref_large[100005];
int suff_small[100005];
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> ar[i];
	}
	pref_large[0] = ar[0];
	for(int i = 1; i < n; ++i) {
		pref_large[i] = max(pref_large[i - 1], ar[i]);
	}
	suff_small[n - 1] = ar[n - 1];
	for(int i = n - 2; i >= 0; --i) {
		suff_small[i] = min(suff_small[i + 1], ar[i]);
	}
	int res = 0;
	for(int i = 0; i < n; ++i) {
		if(suff_small[i] == pref_large[i]) {
			res++;
		}
	}
	cout << res << endl;
	return 0;
}