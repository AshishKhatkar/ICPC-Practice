/*
Author : lifecodemohit
Problem : http://codeforces.com/gym/100800/attachments/download/3803/united-kingdom-and-ireland-programming-contest-2015-ukiepc-2015-en.pdf
Problem A
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

#define MOD 1000000007

int main()
{
	scanf("%d %d %d %d", &n, &s, &t, &len);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &x[i], &y[i], &h[i]);
	}

	double DP[n+1][n+1];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				DP[i][j] = 0.0;
			else {
				DP[i][j] = hypot(x[j] - x[i], y[j] - y[i]);
				if ((h[j] >= h[i]) || (DP[i][j] > len))
					DP[i][j] = MOD*1.0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j])
			}
		}
	}


	return 0;
}