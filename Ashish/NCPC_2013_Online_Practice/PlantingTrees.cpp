#include<bits/stdc++.h>
using namespace std;
#define ll				long long int
#define MOD				1000000007
#define rep(i, a, b)	for(i=a; i<=b; ++i)
#define rrep(i, a, b)	for(i=a; i>=b; --i)
#define si(a)			scanf("%d", &a)
#define sl(a)			scanf("%lld", &a)
#define pi(a)			printf("%d", a)
#define pl(a)			printf("%lld", a)
#define pn 				printf("\n")
ll pow_mod(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b & 1)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}
int ar[100005];
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> ar[i];
	}
	sort(ar, ar + n);
	reverse(ar, ar + n);
	int res = 0;
	for(int i = 0; i < n; ++i) {
		res = max(res, ar[i] + i + 1);
	}
	res++;
	cout << res << endl;
	return 0;
}