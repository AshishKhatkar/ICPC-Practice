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
char board[12][12];
bool solve(int rows, int cols, string str) {
	int idx = 0;
	for(int i = 0; i < rows; ++i) {
		for(int j = 0; j < cols; ++j) {
			board[i][j] = str[idx];
			idx++;
		}
	}
	for(int i = 0; i < cols; ++i) {
		bool found = true;
		for(int j = 0; j < rows; ++j) {
			if(board[j][i] == 'O') {
				found = false;
				break;
			}
		}
		if(found) {
			return true;
		}
	}
	return false;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		string str;
		cin >> str;
		vector<pair<int, int> > res;
		if(solve(1, 12, str)) {
			res.push_back(make_pair(1, 12));
		}
		if(solve(2, 6, str)) {
			res.push_back(make_pair(2, 6));
		}
		if(solve(3, 4, str)) {
			res.push_back(make_pair(3, 4));
		}
		if(solve(4, 3, str)) {
			res.push_back(make_pair(4, 3));
		}
		if(solve(6, 2, str)) {
			res.push_back(make_pair(6, 2));
		}
		if(solve(12, 1, str)) {
			res.push_back(make_pair(12, 1));
		}
		cout << (int)(res.size()) << " ";
		for(int i = 0; i < (int)(res.size()); ++i) {
			cout << res[i].first << "x" << res[i].second << " ";
		}
		cout << endl;
	}
	return 0;
}