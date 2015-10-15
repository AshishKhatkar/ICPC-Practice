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
int ar[105], ar1[105];
int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> ar[i];
	}
	sort(ar + 1, ar + n + 1);
	int m;
	cin >> m;
	for(int i = 1; i <= m; ++i) {
		cin >> ar1[i];
	}
	sort(ar1 + 1, ar1 + m + 1);
	int idx = 1, idx1 = 1;
	int res = 0;
	while(idx <= n && idx1 <= m) {
		if(abs(ar[idx] - ar1[idx1]) <= 1) {
			res++;
			idx++;
			idx1++;
		} else if(ar[idx] > ar1[idx1]) {
			idx1++;
		} else {
			idx++;
		}
	}
	cout << res << endl;
	return 0;
}