/*
Author : lifecodemohit
Problem : Ballot FCP
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
	int n, b;
	si(n);	si(b);
	int a[n+1];
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		si(a[i]);
		sum += a[i];
	}
	ll low = 0;
	ll high = sum;
	while (low < high) {
		ll mid = low + (high - low)/2 ;
		//cout << low << " " << high << " " << mid << endl;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt = cnt + a[i]/mid;
			if (a[i]%mid != 0)
				cnt++;
		}
		if (cnt > b)
			low = mid+1;
		else
			high = mid;
	}
	pn(low);
	return 0;
}