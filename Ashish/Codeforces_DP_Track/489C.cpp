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
string compute_min(int m, int s) {
	if(s == 0) {
		return "0";
	}
	string res = "";
	m--;
	s--;
	while(m--) {
		if(s > 9) {
			res = '9' + res;
			s -= 9;
		} else {
			res = (char)(s + '0') + res; 
			s = 0;
		}
	}
	if(s) {
		res = (char)(s + 1 + '0') + res;
	} else {
		res = '1' + res;
	}
	return res;
}
string compute_max(int m, int s) {
	if(s == 0) {
		return "0";
	}
	string res = "";
	while(m--) {
		if(s > 9) {
			res = res + (char)(9 + '0');
			s -= 9;
		} else {
			res = res + (char)(s + '0');
			s = 0;
		}
	}
	return res;
}
int main() {
	int m, s;
	cin >> m >> s;
	if(s > 9 * m || (s == 0 && m >= 2)) {
		cout << "-1 -1\n";
	} else {
		cout << compute_min(m, s) << " " << compute_max(m, s) << endl;
	}
	return 0;
}