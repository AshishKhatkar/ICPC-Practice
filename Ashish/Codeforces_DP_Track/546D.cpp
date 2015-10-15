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
bool isPrime[5000005];
int smp[5000005];
int fac[5000005];
int res[5000005];
void sieve() {
	memset(isPrime, true, sizeof(isPrime));
	isPrime[1] = false;
	for(int i = 2; i <= 5000000; ++i) {
		if(isPrime[i]) {
			smp[i] = i;
			for(int j = 2 * i; j <= 5000000; j += i) {
				if(isPrime[j]) {
					smp[j] = i;
				}
				isPrime[j] = false;
			}
		}
	}
	fac[1] = 0;
	for(int i = 2; i <= 5000000; ++i) {
		if(isPrime[i]) {
			fac[i] = 1;
		} else {
			fac[i] = 1 + fac[i / smp[i]];
		}
	}
	res[1] = 0;
	for(int i = 2; i <= 5000000; ++i) {
		res[i] = res[i - 1] + fac[i];
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	sieve();
	int t;
	// cin >> t;
	si(t);
	while(t--) {
		int a, b;
		// cin >> a >> b;
		si(a); si(b);
		pi(res[a] - res[b]);
		pn;
		// cout << (res[a] - res[b]) << endl;
	}
	return 0;
}