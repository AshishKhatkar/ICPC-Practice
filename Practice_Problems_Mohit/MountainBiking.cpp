/*
Author : lifecodemohit
Problem : http://codeforces.com/gym/100800/attachments/download/3803/united-kingdom-and-ireland-programming-contest-2015-ukiepc-2015-en.pdf
Problem B
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
#define PI 3.14159265

int main()
{
	int n;
	double g;
	scanf("%d %lf", &n, &g);
	int d[n+1], an[n+1];
	for (int  i = 0; i < n; i++) {
		scanf("%d %d", &d[i], &an[i]);
	}
	for (int i = 0; i < n; i++) {
		double u2 = 0.0;
		for (int j = i; j < n; j++) {
			u2 = u2 + 2*g*d[j]*cos((an[j]*PI)/180.0);
		}
		printf("%.6f\n",sqrt(u2));
	}
	return 0;
}