/*
Author : lifecodemohit
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

struct sqrt1 {
	int x; int y; int z; int w;
};

struct by_z {
	bool operator() (const sqrt1 & a, const sqrt1 & b) {
		if (a.z == b.z) {
			return a.x < b.x;
		}
		return a.z < b.z;
	}
};

long long result = 0;
long long cnt[1000010];
long long  a[100010];

set < long long > set1;

void add(int pos) {

	if (cnt[a[pos]] == 0) {
		cout << a[pos] << endl;
		set1.insert(a[pos]);
		set < long long >::iterator low = lower_bound(set1.begin(), set1.end(), a[pos]);
		set < long long >::iterator up = upper_bound(set1.begin(), set1.end(), a[pos]);
		if (low != set1.begin()) {
			set < long long >::iterator low1 = low--;
			result = result + (a[pos] - (*low1))*(a[pos] - (*low1));
			low++;
		}
		cout << result << endl;
		if (up != set1.end()) {
			result = result + ((*up) - a[pos])*((*up) - a[pos]);
		}
		cout << result << endl;
		if ((low != set1.begin()) && (up != set1.end())) {
			set < long long >::iterator low1 = low--;
			result = result - ((*up) - (*low1))*((*up) - (*low1));
		}
		cout << result << endl;
	}	
	cnt[a[pos]]++; 
}

void rem(int pos) {
	if (cnt[a[pos]] == 1) {
		set < long long >::iterator low = lower_bound(set1.begin(), set1.end(), a[pos]);
		set < long long >::iterator up = upper_bound(set1.begin(), set1.end(), a[pos]);
		if (low != set1.begin()) {
			set < long long >::iterator low1 = low--;
			result = result - (a[pos] - (*low1))*(a[pos] - (*low1));
			low++;
		}
		if (up != set1.end()) {
			result = result - ((*up) - a[pos])*((*up) - a[pos]);
		}
		if ((low != set1.begin()) && (up != set1.end())) {
			set < long long >::iterator low1 = low--;
			result = result + ((*up) - (*low1))*((*up) - (*low1));
		}
		set1.erase(a[pos]);

	}
	cnt[a[pos]]--;
}

int main()
{
	int n;
	memset(cnt, 0, sizeof(cnt));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}

	int q;
	scanf("%d", &q);
	int rotn = sqrt(n);
	vector < sqrt1 > s1;
	for (int  i = 0; i < q; i++) {
		struct sqrt1 s;
		scanf("%d %d", &s.x, &s.y);
		s.z = s.z / rotn;
		s.w = i;
		s1.push_back(s);
	}
	sort(s1.begin(), s1.end(), by_z());

	int curL = 0, curR = 0, L, R;
	add(0);
	long long res[q+1];
	for (int  i = 0; i < q; i++) {
		L = s1[i].x - 1;
		R = s1[i].y - 1;
		while (curL < L) {
			rem(curL);
			curL++;
		}
		while ((curL - 1) >= L) {
			curL--;
			add(curL);
		}
		while ((curR + 1) <= R) {
			curR++;
			add(curR);
		}
		while (curR > R) {
			rem(curR);
			curR--;
		}
		cout << "L : " << L << " , " << " R : " << R << " , " << result << endl;  
		res[s1[i].w] = result;
	}	
	for (int  i = 0; i < q; i++) {
		printf("%lld\n", res[i]);
	}
	return 0;
}