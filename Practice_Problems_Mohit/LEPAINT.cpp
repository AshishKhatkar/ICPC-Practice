/*
Author : lifecodemohit
Problem : https://www.codechef.com/problems/LEPAINT
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

using namespace std;

#define MOD 			1000000007
#define ll 				long long 
#define si(a)			scanf("%d", &a)
#define sn(a)			scanf("%lld", &a)
#define pi(a)			printf("%d\n", a)
#define pn(a)			printf("%lld\n", a)
#define ss(a)			scanf("%s", a)
#define rep(i, s, e)	for (int i = s; i <= e; i++)
#define rrep(i, s, e)	for (int i = s; i >= e; i--)
#define mem(arr, val)	memset(arr, val, sizeof(arr))
#define pb				push_back
#define mp				make_pair

int main()
{
	int t;
	si(t);
	while (t--) {
	
		long double DP[2][10000];

		int n, k1, c;
		si(n); si(c); si(k1);

		long double A[c][n], T[c][n];

		for (int i = 0; i <= c-1; i++)
			for (int j = 0; j <= n-1; j++)  
				A[i][j] = (i == 1 ? 1 : 0);

		while (k1--) {
			int l, r;
			si(l);	si(r);
			l--; r--;
			for (int k = l; k <= r; k++) {
				for (int i = 0; i <= c-1; i++) {
					T[i][k] = A[i][k];
					A[i][k] = (A[i][k]*0.5);
				}
				for (int i = 0; i <= c-1; i++) {
					for (int j = 0; j <= c-1; j++) {
						A[(i*j)%c][k] += (T[j][k]*(1.0/(2*c)));
					}
				}
			}
		}

		for (int k = 0; k <= (c-1)*n; k++)
			DP[0][k] = 0;
		for (int k = 0; k <= (c-1); k++) 
			DP[0][k] = A[k][0];

		for (int j = 1; j <= n - 1; j++) {
			for (int k = 0; k <= (c-1)*n; k++)
				DP[1][k] = 0;
			for (int i = 0; i <= (c-1); i++) {
				for (int k = 0; k <= (c-1) * n; k++) {
					DP[1][k+i] += DP[0][k]*A[i][j];
				}
			}
			for (int k = 0; k <= (c-1)*n; k++)
				DP[0][k] = DP[1][k];
		}

		long double sum = 0.0;
		for (int k = 0; k <= (c-1)*n; k++)
			sum = sum + k*DP[0][k];

		printf("%.7Lf\n",sum);
	}
	return 0;
}