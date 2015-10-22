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
	string str;
	cin >> str;
	int len = str.length();
	vector<int> v1, v2;
	string tmp = "";
	int idx = -1;
	for(int i = 0; i < len; ++i) {
		if(str[i] == 'B') {
			if(tmp == "") {
				tmp = tmp + 'B';
				idx = i;
			} else {
				tmp = "B";
				idx = i;
			}
		} else if(str[i] == 'A') {
			if(tmp == "B") {
				v1.push_back(idx);
				idx = -1;
				tmp = "";
			} else {
				tmp = "";
				idx = -1;
			}
		} else {
			tmp = "";
			idx = -1;
		}
	}
	tmp = "";
	idx = -1;
	for(int i = 0; i < len; ++i) {
		if(str[i] == 'A') {
			if(tmp == "") {
				tmp = tmp + 'A';
				idx = i;
			} else {
				tmp = "A";
				idx = i;
			}
		} else if(str[i] == 'B') {
			if(tmp == "A") {
				v2.push_back(idx);
				idx = -1;
				tmp = "";
			} else {
				idx = -1;
				tmp = "";
			}
		} else {
			tmp = "";
			idx = -1;
		}
	}
	int sz1 = v1.size();
	int sz2 = v2.size();
	if(sz1 == 0 || sz2 == 0) {
		cout << "NO\n";
	} else {
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		int st_v1 = v1[0];
		int end_v1 = v1[sz1 - 1];
		int st_v2 = v2[0];
		int end_v2 = v2[sz2 - 1];
		// cout << st_v1 << " " << st_v2 << " " << end_v1 << " " << end_v2 << endl;
		if(abs(end_v1 - end_v2) > 1) {
			cout << "YES\n";
		} else if(abs(end_v1 - st_v2) > 1) {
			cout << "YES\n";
		} else if(abs(end_v2 - st_v1) > 1) {
			cout << "YES\n";
		} else if(abs(st_v1 - st_v2) > 1) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}