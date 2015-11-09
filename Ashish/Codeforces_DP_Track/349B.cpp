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
int ar[10];
int main() {
	int n;
	cin >> n;
	int minx = INT_MAX;
	for(int i = 1; i <= 9; ++i) {
		cin >> ar[i];
		minx = min(minx, ar[i]);
	}
	if(n < minx) {
		cout << "-1\n";
	} else {
		minx = INT_MAX;
		int idx = 0;
		for(int i = 1; i <= 9; ++i) {
			if(ar[i] <= minx) {
				minx = ar[i];
				idx = i;
			}
		}
		vector<int> v;
		for(int i = 1; i <= (n / minx); ++i) {
			v.push_back(idx);
		}
		n %= minx;
		for(int i = 0; i < (int)(v.size()); ++i) {
			for(int j = 9; j >= 1; --j) {
				if(n + ar[idx] >= ar[j]) {
					v[i] = j;
					n = n + ar[idx] - ar[j];
					break;
				}
			}
		}
		for(int i = 0; i < (int)(v.size()); ++i) {
			cout << v[i];
		}
		cout << endl;
	}
	return 0;
}