/*
Author : lifecodemohit
Problem : http://www.spoj.com/problems/DEPOSIT/
*/

#ifdef __APPLE__

    #include <cassert>
    #include <iostream>
    #include <iomanip>
    #include <ctime>
    #include <cstdio>
    #include <vector>
    #include <algorithm>
    #include <utility>
    #include <queue>
    #include <stack>
    #include <string>
    #include <cstring>
    #include <sstream>
    #include <map>
    #include <set>
    #include <unordered_map>
    #include <unordered_set>

#else

    #include <bits/stdc++.h>

#endif  

using namespace std;

int main()
{
	long long f[22];
	f[0] = 0;	f[1] = 1;
	for (int i = 2; i <= 21; i++)
		f[i] = f[i-1] + f[i-2];

	while (1) {
		int r;
		scanf("%d", &r);
		if (r == 0)
			break;
		long long k;
		long long T;
		scanf("%lld %lld", &k, &T);
		assert(r >= 2);
		long long left = f[1];
		long long right = f[2];
		for (int i = 2; i < r; i++) {
			left = left + f[i-1];
			right = right + f[i];
		}
		for (long long i = left; i <= T; i = i + left) {
			if ((T-i)%right == 0) {
				long long val = (T-i)/right;
				long long x = min(i/left, val);
				long long y = max(i/left, val);
				long long sol = (f[r-2]*x + f[r-1]*y)*k;
				printf("%lld %lld %lld\n", x, y, sol);
				break;
			}
		}
	}
	return 0;
}