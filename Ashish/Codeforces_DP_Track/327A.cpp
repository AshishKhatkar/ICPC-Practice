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
int ar[105];
int cnt0[105], cnt1[105];
int main() {
	int n;
	cin >> n;
	int to = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> ar[i];
	}
	for(int i = 1; i <= n; ++i) {
		cnt0[i] = cnt0[i - 1];
		if(ar[i] == 0) {
			cnt0[i]++;
		}
	}
	for(int i = 1; i <= n; ++i) {
		cnt1[i] = cnt1[i - 1];
		if(ar[i] == 1) {
			cnt1[i]++;
		}
	}
	to = cnt1[n];
	int res = 0, idx1, idx2;
	for(int i = 1; i <= n; ++i) {
		for(int j = i; j <= n; ++j) {
			int z = cnt0[j] - cnt0[i - 1];
			int o = cnt1[j] - cnt1[i - 1];
			res = max(res, to - o + z);
		}
	}
	cout << res << endl;
	return 0;
}