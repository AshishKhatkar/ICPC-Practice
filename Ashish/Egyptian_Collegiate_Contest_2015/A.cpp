/*
ID: ashish1610
PROG:
LANG: C++
*/
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
int main() {
	int t;
	cin >> t;
	while(t--) {
		string str;
		cin >> str;
		int len = str.length();
		int cnt = 0;
		int tot = 1;
		for(int i = 2; i <= len; ++i) {
			tot *= i;
		}
		for(int i = 0; i < len; ++i) {
			int tmp = 1;
			for(int j = i + 1; j < len; ++j) {
				if(str[i] == str[j]) {
					tmp++;
				}
			}
			for(int j = 1; j <= tmp; ++j) {
				tot /= j;
			}
		}
		while(next_permutation(str.begin(), str.end())) {
			cnt++;
		}
		sort(str.begin(), str.end());
		if(cnt == 0) {
			printf("0.000000000\n");
		} else {
			long double res = powl(((tot + 1) * 1.0) / (tot * 1.0), cnt - 1);
			res = res / (tot * 1.0);
			cout << fixed << setprecision(9) << res << endl;
		}
	}
	return 0;
}