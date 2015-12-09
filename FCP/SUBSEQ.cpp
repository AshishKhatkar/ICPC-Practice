/*
Author : lifecodemohit
*/

#ifdef __APPLE__

    #include <cassert>
    #include <iostream>
    #include <iomanip>
    #include <ctime>
    #include <cstdio>
    #include <vector>
    #include <algorithm>
    #include <utility>
    #include <queue>
    #include <stack>
    #include <string>
    #include <cstring>
    #include <sstream>
    #include <map>
    #include <set>
    #include <unordered_map>
    #include <unordered_set>

#else

    #include <bits/stdc++.h>

#endif  

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		string str;
		int ans = 0;
		cin >> str;
		int res[str.length()];
		for (int i = 0; i < str.length(); i++) {
			res[i] = 1;
			for (int j = i-1; j >= 0; j--) {
				if (str[j] <= str[i]) {
					res[i] = max(res[i], res[j] + 1);
				} 
			}
			ans = max(ans, res[i]);
		}
		cout << ans << endl;
	}

	return 0;
}