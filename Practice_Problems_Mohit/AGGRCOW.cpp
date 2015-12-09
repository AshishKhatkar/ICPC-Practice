
/*
Author : lifecodemohit
Problem : http://www.spoj.com/problems/AGGRCOW/
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
// #include <bits/stdc++.h>

using namespace std;

#define MOD 						1000000007
#define ll 							long long 
#define si(a)						scanf("%d", &a)
#define sn(a)						scanf("%lld", &a)
#define pi(a)						printf("%d\n", a)
#define pn(a)						printf("%lld\n", a)
#define ss(a)						scanf("%s", a)
#define rep(i, s, e)				for (int i = s; i <= e; i++)
#define rrep(i, s, e)				for (int i = s; i >= e; i--)
#define mem(arr, val)				memset(arr, val, sizeof(arr))
#define fill(arr, s, e, val)		for (int i = s; i <= e; i++)	arr[i] = val;
#define pb							push_back
#define mp							make_pair

int main()
{
	int t;
	si(t);
	while (t--) {
		int n, k;
		si(n);	si(k);
		ll a[n+1];
		for (int i = 0; i < n; i++)
			sn(a[i]);
		sort(a, a+n);
		ll low = *min_element(a, a+n);
		ll high = (a[n-1] - a[0] + 1)/(k-1);
		while (low < high) {
			ll mid = low + (high - low + 1)/2;
			ll last = a[0];
			int cnt = 1;
			for (int i = 1; i < n; i++) {
				if ((a[i]-last) >= mid) {
					cnt++;
					last = a[i];
				}
			}
			if (cnt < k)
				high = mid - 1;
			else
				low = mid;
		}
		pn(low);
	}
	return 0;
}