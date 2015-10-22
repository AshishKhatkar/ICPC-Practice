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
int ar[200005];
map<ll, ll> mp[2];
int main() {
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; ++i) {
		cin >> ar[i];
	}
	ll res = 0;
	for(int i = 0; i < n; ++i) {
		if(abs(ar[i]) % k == 0) {
			res += mp[1][ar[i] / k];
			mp[1][ar[i]] += mp[0][ar[i] / k];
			mp[0][ar[i]] += 1;
		} else {
			mp[0][ar[i]]++;
		}
	}
	cout << res << endl;
	return 0;
}