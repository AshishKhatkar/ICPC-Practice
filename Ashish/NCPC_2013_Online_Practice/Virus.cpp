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
	string str, str1;
	cin >> str >> str1;
	int len = str.length();
	int len1 = str1.length();
	int i = 0, j = 0;
	while(i < len && j < len1 && str[i] == str1[j]) {
		i++;
		j++;
	}
	int idx1 = j;
	i = len - 1;
	j = len1 - 1;
	while(i >= 0 && j >= 0 && str[i] == str1[j]) {
		i--;
		j--;
	}
	int idx2 = j;
	cout << max(len1 - len, max(0, idx2 - idx1 + 1)) << endl;
	return 0;
}