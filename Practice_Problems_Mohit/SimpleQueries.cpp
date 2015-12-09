/*
Author : lifecodemohit
Problem : Simple Queries FCP
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

long long ar[2000010];
long long cnt[2000010];

int main()
{
	long long t;
	scanf("%lld", &t);
	while (t--) {
		long long n, m, Lo, Ro, Co, P, Q, S;
		scanf("%lld", &n);
		scanf("%lld %lld", &ar[1], &ar[2]);
		scanf("%lld", &m);
		scanf("%lld %lld %lld", &P, &Q, &S);
		scanf("%lld %lld %lld", &Lo, &Ro, &Co);
		long long ar_gen1 = ar[1], ar_gen2 = ar[2];
		for(long long i = 3; i <= n; ++i) {
			ar[i] = (ar[i - 1] * ar_gen1 + ar_gen2) % 1000000 + 1;
			ar_gen1 = ar[i - 1];
			ar_gen2 = ar[i];
		}
		memset(cnt, 0, sizeof(cnt));
		while (m--) {
			long long L1 = (Lo * P + Ro) % n + 1;
			long long R1 = (Ro * Q + Lo) % n + 1;
			if(L1 > R1)
				swap(L1 , R1);
			long long C1 = (Co * S) % 1000000 + 1;
			Lo = L1;
			Ro = R1;
			Co = C1;
			cnt[Ro] += Co;
			if (Lo > 0)
				cnt[Lo-1] -= Co;
		}
		long long maxi = (long long)ar[n] + cnt[n];
		long long mini = maxi;
		for (long long i = n-1; i >= 1; i--) {
			cnt[i] = cnt[i] + cnt[i+1];
			maxi = max(maxi, (long long)ar[i] + cnt[i]);
			mini = min(mini, (long long)ar[i] + cnt[i]);
		}
		printf("%lld %lld\n", maxi, mini);
	}
	return 0;
}