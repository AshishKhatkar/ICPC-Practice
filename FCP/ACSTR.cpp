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
		cin >> str;
		int cnt1[26], cnt2[26];
		memset(cnt1, 0, sizeof(cnt1));
		memset(cnt2, 0, sizeof(cnt2));
		for (int i = 0; i < str.length(); i++)
			cnt1[str[i] - 'a']++;
		cin >> str;
		for (int i = 0; i < str.length(); i++) 
			cnt2[str[i] - 'a']++;
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < min(cnt1[i], cnt2[i]); j++) 
				cout << (char)(i + 97) ;
		cout << endl; 
	}
	return 0;
}