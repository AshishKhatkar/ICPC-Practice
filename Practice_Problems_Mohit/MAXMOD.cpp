/*
Author : lifecodemohit
Problem : FCP MAXMOD
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
#include <bits/stdc++.h>

using namespace std;

int a[200010];

int main()
{
	int n;
	scanf("%d", &n);
	int MAXN = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		MAXN = max(MAXN, a[i]);
	}
	sort(a, a + n);
	int start = lower_bound(a, a+n, 2) - a;
	int ans = 0;
	for (int i = start; i < n; i++) {
		int start1 = a[i] + a[i];
		for (int j = start1; j <= 2*MAXN; j += a[i]) {
			int val = lower_bound(a, a+n, j) - a;
			ans = max(ans, a[val-1]%a[i]);
		}
	} 
	printf("%d\n", ans);
	return 0;
}