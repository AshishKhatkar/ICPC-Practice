/*
Author : lifecodemohit
Problem : FCP Mountain
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

long long DP[300][105][105];
int MOD = 1000000007;

long long solve(int stick, int cnt, int n) {
	// cout << stick << " " << cnt << endl;
	if (stick == 0)
		return 1;
	if (DP[stick][cnt][n] != 0)
		return DP[stick][cnt][n];
	if (cnt == 0) {
		DP[stick][cnt][n] = solve(stick - 1, cnt + 1, n-1);
	}
	else if (n == 0) {
		DP[stick][cnt][n] = solve(stick - 1, cnt - 1, n);
	}
	else {
		DP[stick][cnt][n] = (solve(stick - 1, cnt + 1, n-1) + solve(stick - 1, cnt - 1, n)) % MOD;
	}
	return DP[stick][cnt][n];
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(DP, 0, sizeof(DP));
		int n;
		scanf("%d", &n);
		printf("%lld\n", solve(2*n, 0, n));
	}
	return 0;
}