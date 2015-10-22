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
int ar[100005];
bool done[100005];
pair<int, int> queries[100005];
int res[100005];
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		cin >> ar[i];
	}
	for(int i = 0; i < m; ++i) {
		cin >> queries[i].first;
		queries[i].first--;
		queries[i].second = i;
	}
	sort(queries, queries + m);
	reverse(queries, queries + m);
	int j = n - 1;
	int cnt = 0;
	for(int i = 0; i < m; ++i) {
		while(queries[i].first <= j) {
			if(!done[ar[j]]) {
				done[ar[j]] = true;
				cnt++;
			}
			j--;
		}
		res[queries[i].second] = cnt;
	}
	for(int i = 0; i < m; ++i) {
		cout << res[i] << endl;
	}
	return 0;
}