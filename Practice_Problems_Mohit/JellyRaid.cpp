/*
Author : lifecodemohit
Problem : http://codeforces.com/gym/100800/attachments/download/3803/united-kingdom-and-ireland-programming-contest-2015-ukiepc-2015-en.pdf
Problem J
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

int a[65][65];
int arr[120][65][65];
bool visit[65][65];

int main()
{
	memset(visit, false, sizeof(visit));
	priority_queue < pair < int, pair < int, int > > > pq;

	int n, m;
	cin >> n >> m;
	getchar();
	string str;
	getline(cin, str);
	stringstream ss(str);
	string word;
	

	ss >> word;
	int x1 = stoi(word.substr(1, word.length())) - 1;
	ss >> word;
	int y1 = stoi(word.substr(0, word.length()-1)) - 1;

	ss >> word;
	int x2 = stoi(word.substr(1, word.length())) - 1;
	ss >> word;
	int y2 = stoi(word.substr(0, word.length()-1)) - 1;

	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			a[i][j] = (str[j] == '.' ? 1 : 0);
		}
	}

	for (int  i= 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		} 
		cout << endl;
	}
	int q;
	cin >> q;
	int num[q+1], x[q+1][10], y[q+1][10], pt[q+1];
	bool dir[q+1];
	getchar();
	for (int i = 0; i < q; i++) {
		string str1;
		getline(cin, str1);
		stringstream ss1(str1);
		ss1 >> word;
		num[i] = stoi(word);
		int j = -1;
		bool flag = true;
		pt[i] = -1;
		dir[i] = true;
		while ((ss1 >> word)) {
			if (flag) {
				j++;
				x[i][j] = stoi(word.substr(1, word.length())) - 1;
			}
			else
				y[i][j] = stoi(word.substr(0, word.length()-1)) - 1;
			flag = !flag;
		}
	}

	map < int, int > m1[121], m2[121];

	for (int i = 0; i < 120; i++) {

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				arr[i][j][k] = a[j][k];
			}
		}

		for (int j = 0; j < q; j++) {

			if (dir[j])	pt[j]++;
			else pt[j]--;

			if ((dir[j]) && (pt[j] == num[j])) {
				dir[j] = !dir[j];
				pt[j] = max(num[j]-2, num[j]-1);
			}
			if ((!dir[j]) && (pt[j] == -1)) {
				dir[j] = !dir[j];
				pt[j] = max(num[j]-1, 1);
			}

			arr[i][x[j][pt[j]]][y[j][pt[j]]] = 0;

			m1[i][x[j][pt[j]]] = 1;
			m2[i][y[j][pt[j]]] = 1;
		}

	}

	if ((x1 == x2) && (y1 == y2))
		cout << 0 << endl;
	else if ((m1[0][x1] == 1) || (m2[0][y1] == 1)) 
		cout << "YOOIMPOSSIBLE" << endl;
	else {
		pq.push(make_pair(0, make_pair(x1, y1)));
		int cnt = 0, cnt1 = 0;
		bool flag = false;
		while (cnt <= 1000) {
			pair < int , pair < int, int > > t1 = pq.top();
			pq.pop();
			pair < int , int > t2 = t1.second;
			cout << t2.first << " " << t2.second << endl;
			if ((t2.first == x2) && (t2.second == y2)) {
				flag = true;
				cout << t1.first << endl;
				break;
			}
			if ((m1[cnt1][t2.first] == 1) || (m2[cnt1][t2.second] == 1)) {
				pq.push(make_pair(t1.first+1, t2));
			}
			else {
				if ((t2.first-1 >= 0) && (t2.second >= 0) && (a[t2.first-1][t2.second] == 1) && (!visit[t2.first-1][t2.second])) {
					cout << "HII " << t2.first - 1 << " " << t2.second << endl;
					pq.push(make_pair(t1.first+1, make_pair(t2.first-1, t2.second)));
					visit[t2.first-1][t2.second] = true;
				}
				if ((t2.first+1 < n) && (t2.second >= 0) && (a[t2.first+1][t2.second] == 1) && (!visit[t2.first+1][t2.second])) {
					pq.push(make_pair(t1.first+1, make_pair(t2.first+1, t2.second)));
					visit[t2.first+1][t2.second] = true;
				}
				if ((t2.first >= 0) && (t2.second-1 >= 0) && (a[t2.first][t2.second-1] == 1) && (!visit[t2.first][t2.second-1])) {
					pq.push(make_pair(t1.first+1, make_pair(t2.first, t2.second-1)));
					visit[t2.first][t2.second-1] = true;
				}
				if ((t2.first >= 0) && (t2.second+1 < m) && (a[t2.first][t2.second+1] == 1) && (!visit[t2.first][t2.second+1])) {
					pq.push(make_pair(t1.first+1, make_pair(t2.first, t2.second+1)));
					visit[t2.first][t2.second+1] = true;
				}
			}
			cnt++;
			cnt1 = (cnt1+1)%120;
		}
		if (!flag)
			cout << "IMPOSSIBLE" << endl;
	}

 	return 0;
}

