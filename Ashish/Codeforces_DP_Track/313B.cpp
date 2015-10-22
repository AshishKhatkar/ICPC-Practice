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
int cnt[100005];
int main() {
	string str;
	cin >> str;
	str = str + 'A';
	int len = str.length();
	if(str[0] == str[1]) {
		cnt[0] = 1;
	} else {
		cnt[0] = 0;
	}
	for(int i = 1; i < len; ++i) {
		cnt[i] = cnt[i - 1];
		if(str[i] == str[i + 1]) {
			cnt[i]++;
		}
	}
	int m;
	cin >> m;
	while(m--) {
		int l, r;
		cin >> l >> r;
		r--;
		l--;
		if(l) {
			if(str[r] == str[r + 1]) {
				cout << cnt[r] - cnt[l - 1] - 1 << endl;
			}
			else {
				cout << cnt[r] - cnt[l - 1] << endl;
			}
		} else {
			if(str[r] == str[r + 1]) {
				cout << cnt[r] - 1 << endl;
			} else {
				cout << cnt[r] << endl;
			}
		}
	}
	return 0;
}