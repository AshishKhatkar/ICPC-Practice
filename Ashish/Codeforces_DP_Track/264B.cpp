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
vector<int> primes[100005];
bool is_prime[100005];
int dp[100005];
void sieve() {
	memset(is_prime, true, sizeof(is_prime));
	is_prime[1] = false;
	for(int i = 2; i <= 100000; ++i) {
		if(is_prime[i]) {
			primes[i].push_back(i);
			for(int j = 2 * i; j <= 100000; j += i) {
				is_prime[j] = false;
				primes[j].push_back(i);
			}
		}
	}
}
int main() {
	sieve();
	int n, x;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	int max_val = 0;
	for(int i = 0; i < n; ++i) {
		cin >> x;
		max_val = max(max_val, x);
		if(i == 0) {
			for(int j = 0; j < (int)(primes[x].size()); ++j) {
				dp[primes[x][j]] = 1;
			}
		} else {
			int maxx = -1;
			for(int j = 0; j < (int)(primes[x].size()); ++j) {
				maxx = max(maxx, dp[primes[x][j]]);
			}
			for(int j = 0; j < (int)(primes[x].size()); ++j) {
				if(maxx == -1) {
					dp[primes[x][j]] = 1;
				} else {
					dp[primes[x][j]] = maxx + 1;
				}
			}
		}
	}
	int res = 1;
	for(int i = 1; i <= max_val; ++i) {
		res = max(res, dp[i]);
	}
	cout << res << endl;
	return 0;
}