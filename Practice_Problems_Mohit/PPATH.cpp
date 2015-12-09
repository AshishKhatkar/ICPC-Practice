/*
Author : lifecodemohit
*/

#ifdef __APPLE__
    #include<cassert>
    #include<iostream>
    #include<iomanip>
    #include<ctime>
    #include<cstdio>
    #include<vector>
    #include<algorithm>
    #include<utility>
    #include<queue>
    #include<stack>
    #include<string>
    #include<cstring>
    #include<sstream>
    #include<map>
    #include<set>
    #include<unordered_map>
    #include<unordered_set>

#else

    #include<bits/stdc++.h>

#endif  

using namespace std;

int main()
{
	bool prime[100001];
	for (int i = 1000; i <= 9999; i++) {
		bool flag = true;
		for (int j = 2; j <= sqrt(i); j++)
			if (i%j == 0) {
				flag = false;
				break;
			}
		prime[i] = flag;
	}

	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		bool visit[100010];
		memset(visit, false, sizeof(visit));
		queue < pair < int, int > > q1;
		q1.push(make_pair(n, 0));
		visit[n] = true;
		while (!q1.empty()) {
			int top = q1.front().first;
			int par_dis = q1.front().second;
			if (top == m)
				break;
			for (int i = 0; i < 4; i++) {
				int front = top/(int)pow(10, i+1);
				int back = top%(int)pow(10, i);
				int cur = top%(int)pow(10, i+1) - back;
				for (int j = (i != 3 ? 0 : 1); j <= 9; j++) {
					int num = front*pow(10, i+1) + j*pow(10, i) + back;
					if (!visit[num] && (prime[num])) {
						q1.push(make_pair(num, par_dis + 1));
						visit[num] = true;
					}
				}
			}
			q1.pop();
		}
		if (!q1.empty())
			printf("%d\n", q1.front().second);
		else
			printf("Impossible\n");
	}
	return 0;
}