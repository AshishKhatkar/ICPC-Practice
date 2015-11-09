/*
ID: ashish1610
PROG:
LANG: C++
*/
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
int main() {
	ll m, n, t;
	cin >> m >> n >> t;
	if(t == 1) {
		ll val = 1;
		for(ll i = 1; i <= n && val <= m; ++i) {
			val *= i;
		}
		if(val > m) {
			printf("TLE\n");
		} else {
			printf("AC\n");
		}
	} else if(t == 2) {
		ll val = 1;
		for(ll i = 1; i <= n && val <= m; ++i) {
			val *= 2;
		}
		if(val > m) {
			printf("TLE\n");
		} else {
			printf("AC\n");
		}
	} else if(t == 3) {
		ll val = 1;
		for(ll i = 1; i <= 4 && val <= m; ++i) {
			val *= n;
		}
		if(val > m) {
			printf("TLE\n");
		} else {
			printf("AC\n");
		}
	} else if(t == 4) {
		ll val = 1;
		for(ll i = 1; i <= 3 && val <= m; ++i) {
			val *= n;
		}
		if(val > m) {
			printf("TLE\n");
		} else {
			printf("AC\n");
		}
	} else if(t == 5) {
		ll val = n * n;
		if(val > m) {
			printf("TLE\n");
		} else {
			printf("AC\n");
		}
	} else if(t == 6) {
		ll val = ceil(n * log2(n));
		if(val > m) {
			printf("TLE\n");
		} else {
			printf("AC\n");
		}
	} else if(t == 7) {
		if(n > m) {
			printf("TLE\n");
		} else {
			printf("AC\n");
		}
	}
	return 0;
}