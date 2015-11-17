/*
Author : lifecodemohit
Problem : auckFmbar and Triangles
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

int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int power = pow(2, n);
		for (int i = 0; i < power; i++) {
			for (int j = 0; j < n; j++) {
				if (i & (1 << j))
					cnt++;
			}
			if (cnt % 3 == 0) {

			}
			else {
				for (int j = 0; j < n; j++) {
					if ((i & (1 << j)) == 0) {
						DP[(i | (1 << j))] = max(DP[(i | (1 << j))], DP[i]);
						if (DP[(i | (1 << j))] == DP[i]) {
							VAL[(i | (1 << j))] = min(VAL[(i | (1 << j))], VAL[i] + a[j]);
						}
					}
				}
			}
		}
	}
	return 0;
}