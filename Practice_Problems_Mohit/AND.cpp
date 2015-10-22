/*
Author : lifecodemohit
Problem : https://www.codechef.com/problems/AND
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
#define rep(i, s, e)	for (int i = s; i <= e; i++)
#define rrep(i, s, e)	for (int i = s; i >= e; i--)
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

int main()
{
	int n;
	si(n);
	ll a[n+1];
	vector < int > v1[100010];
	rep(i, 0, n-1) {
		sn(a[i]);
		int val = a[i];
		int cnt = 0;
		while (cnt < 32) {
			int rem = val % 2;
			val = val / 2 ;
			v1[i].push_back(rem);
			cnt++;
		}
	}
	ll ans = 0;
	rep (i, 0, 31) {
		ll cnt = 0;
		rep (j, 0, n-1) {
			if (v1[j][i] == 1)
				cnt++;
		}
		ans = ans + ((cnt*(cnt-1))/2)*PowMod(2, (ll)i, MOD);
	}
	pn(ans);
	return 0;
}