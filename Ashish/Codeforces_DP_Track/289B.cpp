#include<bits/stdc++.h>
using namespace std;
#define ll				long long int
#define vi				vector<int>
#define vl				vector<ll>
#define	pii				pair<int,int>
#define pil				pair<int, ll>
#define pll				pair<ll, ll>
#define pli 			pair<ll, int>
#define pb(v, a)		v.push_back(a)
#define mp(a, b)		make_pair(a, b)
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
int ar[100 * 100 + 5];
int main() {
	int n, m, d;
	cin >> n >> m >> d;
	for(int i = 0; i < n * m; ++i) {
		cin >> ar[i];
	}
	sort(ar, ar + n * m);
	for(int i = 1; i < n * m; ++i) {
		if(ar[i] % d != ar[0] % d) {
			cout << "-1\n";
			return 0;
		}
	}
	int targ = ar[(n * m) / 2];
	ll res = 0;
	for(int i = 0; i < n * m; ++i) {
		res += abs(targ - ar[i]) / d;
	}
	cout << res << endl;
	return 0;
}