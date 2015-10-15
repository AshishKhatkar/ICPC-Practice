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
string str1, str2;
int solve(int idx, int val, int final_pos, int n) {
	if(idx == n) {
		if(val == final_pos) {
			return 1;
		} else {
			return 0;
		}
	}
	int res = 0;
	if(str2[idx] == '+') {
		res = res + solve(idx + 1, val + 1, final_pos, n);
	} else if(str2[idx] == '-') {
		res = res + solve(idx + 1, val - 1, final_pos, n);
	} else {
		res = res + solve(idx + 1, val + 1, final_pos, n);
		res = res + solve(idx + 1, val - 1, final_pos, n);
	}
	return res;
}
int main() {
	cin >> str1 >> str2;
	int len = str1.length();
	int final_pos = 0, qm = 0;
	for(int i = 0; i < len; ++i) {
		if(str1[i] == '+') {
			final_pos++;
		} else {
			final_pos--;
		}
		if(str2[i] == '?') {
			qm++;
		}
	}
	double prob = solve(0, 0, final_pos, len);
	prob /= (1 << qm);
	printf("%0.12lf\n", prob);
	return 0;
}