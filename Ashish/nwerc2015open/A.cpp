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
pair<ll, ll> p[300005];
bool compare(pair<ll, ll> p1, pair<ll, ll> p2) {
	if(p1.first == p2.first) {
		return p1.second < p2.second;
	}
	return p1.first < p2.first;
}
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		cin >> p[i].first >> p[i].second;
	}
	sort(p, p + n, compare);
	priority_queue<pair<ll, int> >  q_rem;
	int res = 0;
	for(int i = 0; i < n; ++i) {
		while(!q_rem.empty() && -1 * q_rem.top().first < p[i].first) {
			q_rem.pop();
		}
		if(!q_rem.empty() && -1 * q_rem.top().second <= p[i].first) {
			res++;
			q_rem.pop();
			q_rem.push(make_pair(-1 * (p[i].first + p[i].second + m), -1 * (p[i].first + p[i].second)));
		} else {
			q_rem.push(make_pair(-1 * (p[i].first + p[i].second + m), -1 * (p[i].first + p[i].second)));
		}
	}
	cout << res << endl;
	return 0;
}