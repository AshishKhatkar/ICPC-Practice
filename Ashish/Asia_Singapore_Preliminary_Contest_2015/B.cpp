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
int ar[4][4], res[4][4];
void out_left() {
	for(int i = 0; i < 4; ++i) {
		for(int j = 0; j < 4; ++j) {
			int val = ar[i][j];
			for(int k = j + 1; k < 4; ++k) {
				if(val == 0 && ar[i][k] != 0) {
					val += ar[i][k];
					ar[i][k] = 0;
				} else if(ar[i][k] == 0 || val == ar[i][k]) {
					if(val != 0 && val == ar[i][k]) {
						val += ar[i][k];
						ar[i][k] = 0;
						break;
					}
					val += ar[i][k];
				} else {
					break;
				}
			}
			ar[i][j] = val;
		}
	}
	for(int i = 0; i < 4; ++i) {
		for(int j = 0; j < 4; ++j) {
			cout << ar[i][j] << " ";
		}
		cout << endl;
	}
}
void out_right() {
	for(int i = 0; i < 4; ++i) {
		for(int j = 3; j >= 0; --j) {
			int val = ar[i][j];
			for(int k = j - 1; k >= 0; --k) {
				if(val == 0 && ar[i][k] != 0) {
					val += ar[i][k];
					ar[i][k] = 0;
				} else if(ar[i][k] == 0 || val == ar[i][k]) {
					if(val != 0 && val == ar[i][k]) {
						val += ar[i][k];
						ar[i][k] = 0;
						break;
					}
					val += ar[i][k];
				} else {
					break;
				}
			}
			ar[i][j] = val;
		}
	}
	for(int i = 0; i < 4; ++i) {
		for(int j = 0; j < 4; ++j) {
			cout << ar[i][j] << " ";
		}
		cout << endl;
	}
}
void out_up() {
	for(int j = 0; j < 4; ++j) {
		for(int i = 0; i < 4; ++i) {
			int val = ar[i][j];
			for(int k = i + 1; k < 4; ++k) {
				if(val == 0 && ar[k][j] != 0) {
					val += ar[k][j];
					ar[k][j] = 0;
				} else if(ar[k][j] == 0 || val == ar[k][j]) {
					if(val != 0 && val == ar[k][j]) {
						val += ar[k][j];
						ar[k][j] = 0;
						break;
					}
					val += ar[k][j];
				} else {
					break;
				}
			}
			ar[i][j] = val;
		}
	}
	for(int i = 0; i < 4; ++i) {
		for(int j = 0; j < 4; ++j) {
			cout << ar[i][j] << " ";
		}
		cout << endl;
	}
}
void out_down() {
	for(int j = 0; j < 4; ++j) {
		for(int i = 3; i >= 0; --i) {
			int val = ar[i][j];
			for(int k = i - 1; k >= 0; --k) {
				if(val == 0 && ar[k][j] != 0) {
					val += ar[k][j];
					ar[k][j] = 0;
				} else if(ar[k][j] == 0 || val == ar[k][j]) {
					if(val != 0 && val == ar[k][j]) {
						val += ar[k][j];
						ar[k][j] = 0;
						break;
					}
					val += ar[k][j];
				} else {
					break;
				}
			}
			ar[i][j] = val;
		}
	}
	for(int i = 0; i < 4; ++i) {
		for(int j = 0; j < 4; ++j) {
			cout << ar[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
	for(int i = 0; i < 4; ++i) {
		for(int j = 0; j < 4; ++j) {
			cin >> ar[i][j];
		}
	}
	int dir;
	cin >> dir;
	if(dir == 0) {
		out_left();
	} else if(dir == 1) {
		out_up();
	} else if(dir == 2) {
		out_right();
	} else {
		out_down();
	}
	return 0;
}