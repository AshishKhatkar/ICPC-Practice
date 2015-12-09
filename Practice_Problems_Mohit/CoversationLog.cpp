/*
Author : lifecodemohit
Problem : http://codeforces.com/gym/100800/attachments/download/3803/united-kingdom-and-ireland-programming-contest-2015-ukiepc-2015-en.pdf
Problem C
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
// #include <bits/stdc++.h>

using namespace std;

struct code {
	int f;
	string s;
};

struct by_comp {
	bool operator() (const code & a, const code & b) {
		if (a.f == b.f)
			return a.s > b.s;
		return a.f < b.f;
	}
};

int main() {
	int n;
	cin >> n;
	char ch;
	ch = getchar();
	map < string , int > m1, m3, m4;
	map < pair < string, string > , int > m2;
	vector < string > v1;
	vector < code > v2;
	int ncnt = 0;
	for (int i = 0; i < n; i++) {
		string str;
		getline(cin, str);
		string name;
		string word;
		int cnt = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ' ' || (i+1 == str.length())) {
				if (i+1 == str.length())
					word = word + str[i];
				if (cnt == 0) {
					name = word;
					if (m4[name] == 0) {
						ncnt++;	
						m4[name] = 1;
					}
				}
				else {
					if (m1[word] == 0)
						v1.push_back(word);
					m1[word]++;
					// cout << word << " " << name << " " << m2[make_pair(word, name)] << endl;
					if (m2[make_pair(word, name)] == 0) {
						m2[make_pair(word, name)] = 1;
						m3[word]++;
					}
				}
				word.clear();
				cnt++;
			}
			else 
				word = word + str[i];
		}
	}
	for (int i = 0; i < (int)v1.size(); i++) {
		struct code S;
		S.f = m1[v1[i]];
		S.s = v1[i];
		v2.push_back(S);
	}

	sort(v2.begin(), v2.end(), by_comp());
	reverse(v2.begin(), v2.end());

	bool flag = false;

	// cout << ncnt << endl;
	for (int i = 0; i < (int)v2.size(); i++) {
		string word = v2[i].s;
		// cout << word << " " << m3[word] << endl;
		if (m3[word] == ncnt) {
			cout << word << endl;
			flag = true;
		}
	}

	if (!flag)
		cout << "ALL CLEAR" << endl;

	return 0;
}