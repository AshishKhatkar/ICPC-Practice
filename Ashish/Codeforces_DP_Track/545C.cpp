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
pair<ll, ll> p[100005];
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> p[i].first >> p[i].second;
	}
	p[n].first = INT_MAX;
	p[n].second = INT_MAX;
	int res = 1;
	int pos = p[0].first;
	for(int i = 1; i < n; ++i) {
		if(p[i].first - p[i].second > pos) {
			res++;
			pos = p[i].first;
		} else if(p[i].first + p[i].second < p[i + 1].first) {
			res++;
			pos = p[i].first + p[i].second;
		} else {
			pos = p[i].first;
		}
	}
	cout << res << endl;
	return 0;
}