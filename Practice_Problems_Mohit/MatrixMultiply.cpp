/*
Author : lifecodemohit
Problem : http://poj.org/problem?id=3318
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
#include <functional>
#include <numeric>
#include <ctime>
// #include <bits/stdc++.h>

using namespace std;

#define MOD 						1000000007
#define ll 							long long 
#define si(a)						scanf("%d", &a)
#define sn(a)						scanf("%lld", &a)
#define pi(a)						prllf("%d\n", a)
#define pn(a)						prllf("%lld\n", a)
#define ss(a)						scanf("%s", a)
#define rep(i, s, e)				for (ll i = s; i <= e; i++)
#define rrep(i, s, e)				for (ll i = s; i >= e; i--)
#define mem(arr, val)				memset(arr, val, sizeof(arr))
#define fill(arr, s, e, val)		for (ll i = s; i <= e; i++)	arr[i] = val;
#define pb							push_back
#define mp							make_pair

void mul(ll A[][1010], ll X[], ll B[], ll n) {

	for (ll i = 0; i < n; i++) {
		B[i] = 0;
		for (ll j = 0; j < n; j++) {
			B[i] = B[i] + A[i][j]*X[j];
		}
	}
}

ll A1[1010][1010], B1[1010][1010], C[1010][1010], D[1010], E[1010], F[1010], X1[1010]; 

int main()
{
	ll n;
	sn(n);
	rep (i, 0, n-1)
		rep(j, 0, n-1)
			sn(A1[i][j]);
	rep (i, 0, n-1)
		rep(j, 0, n-1)
			sn(B1[i][j]);
	rep (i, 0, n-1)
		rep(j, 0, n-1)
			sn(C[i][j]);

	ll T = 5;
	bool flag = true;
	ll k = 5;
	while (T--) {
		rep(i, 0, n-1)
			X1[i] = i + k;
		mul(C, X1, D, n);
		mul(B1, X1, E, n);
		mul(A1, E, F, n);
		for (ll i = 0; i < n; i++) {
			if (D[i] != F[i]) {
				flag = false;
				break;
			}
		}
		k = k*10;
		if(!flag)
			break;
	}
	if (flag)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}