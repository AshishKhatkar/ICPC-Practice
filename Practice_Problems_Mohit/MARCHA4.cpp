/*
Author : lifecodemohit
Problem : https://www.codechef.com/problems/MARCHA4
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

#define MOD 			1000000007
#define ll 				long long 
#define si(a)			scanf("%d", &a)
#define sn(a)			scanf("%lld", &a)
#define pi(a)			printf("%d\n", a)
#define pn(a)			printf("%lld\n", a)
#define ss(a)			scanf("%s", a)
#define rep(i, s, e)	for (i = s; i <= e; i++)
#define rrep(i, s, e)	for (i = s; i >= e; i--)
#define mem(arr, val)	memset(arr, val, sizeof(arr))
#define pb				push_back
#define mp				make_pair

ll PowMod(ll x, ll e, ll mod) {
	if (e == 0)
		return 1 % mod;
	if (e == 1)
		return x % mod;
	ll res = PowMod(x, e >> 1, mod);
	res = (res * res) % mod;
	if (e & 1)
		res = (res * x) % mod;
	return res % mod;
}

ll first(ll n, ll k) {
	long double left = n * log10l(n);
	long double right = powl(10, left - (ll)left);
	ll ans = right * powl(10, k);
	return ans;
}

ll len(ll n) {
	if (n == 0)
		return 1;
	ll cnt = 0;
	while (n) {
		n = n / 10;
		cnt++;
	}
	return cnt;
}
int main()
{
	ll t;
	sn(t);
	while (t--) {
		ll n, k;
		sn(n); sn(k);
		printf("%lld ", first(n, k - 1));
		ll last = PowMod(n, n, powl(10, k));
		if (len(last) < k) {
			for (ll i = 0; i < k - len(last); i++)
				printf("0");
		}
		printf("%lld\n", last);
		
	}
	return 0;
}