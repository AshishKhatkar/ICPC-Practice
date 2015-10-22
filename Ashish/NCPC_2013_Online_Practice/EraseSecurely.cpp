#include<bits/stdc++.h>
using namespace std;
#define ll				long long int
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
	int n;
	cin >> n;
	string str, str1;
	cin >> str >> str1;
	int len = str.length();
	bool flag = true;
	for(int i = 0; i < len; ++i) {
		int old_val = str[i] - '0';
		int cur_val = str1[i] - '0';
		if(n & 1) {
			old_val ^= 1;
		}
		if(cur_val != old_val) {
			flag = false;
			break;
		}
	}
	if(flag) {
		cout << "Deletion succeeded\n";
	} else {
		cout << "Deletion failed\n";
	}
	return 0;
}