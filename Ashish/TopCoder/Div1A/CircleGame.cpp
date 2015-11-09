#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
using namespace std;

class CircleGame {
public:
	int cardsLeft(string);
};

int CircleGame::cardsLeft(string deck) {
	string rem = "";
	map<char, int> mp;
	mp['A'] = 1;
	mp['2'] = 2;
	mp['3'] = 3;
	mp['4'] = 4;
	mp['5'] = 5;
	mp['6'] = 6;
	mp['7'] = 7;
	mp['8'] = 8;
	mp['9'] = 9;
	mp['T'] = 10;
	mp['J'] = 11;
	mp['Q'] = 12;
	mp['K'] = 13;
	int len = deck.length();
	for(int i = 0; i < len; ++i) {
		if(deck[i] != 'K') {
			rem = rem + deck[i];
		}
	}
	len = rem.length();
	while(true) {
		string tmp = "";
		int idx = 0;
		vector<int> v;
		len = rem.length();
		cout << rem << endl;
		while(idx < len) {
			if(mp[rem[idx]] + mp[rem[(idx + 1) % len]] == 13) {
				v.push_back(idx);
				v.push_back((idx + 1) % len);
				idx += 2;
				break;
			} else {
				idx++;
			}
		}
		for(int i = 0; i < len; ++i) {
			bool flag = true;
			for(int j = 0; j < (int)(v.size()); ++j) {
				if(i == v[j]) {
					flag = false;
					break;
				}
			}
			if(flag) {
				tmp = tmp + rem[i];
			}
		}
		rem = tmp;
		if(v.size() == 0) {
			break;
		}
	}
	cout << rem << endl;
	return (int)(rem.length());
}


double test0() {
	string p0 = "KKKKKKKKKK";
	CircleGame * obj = new CircleGame();
	clock_t start = clock();
	int my_answer = obj->cardsLeft(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string p0 = "KKKKKAQT23";
	CircleGame * obj = new CircleGame();
	clock_t start = clock();
	int my_answer = obj->cardsLeft(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string p0 = "KKKKATQ23J";
	CircleGame * obj = new CircleGame();
	clock_t start = clock();
	int my_answer = obj->cardsLeft(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string p0 = "AT68482AK6875QJ5K9573Q";
	CircleGame * obj = new CircleGame();
	clock_t start = clock();
	int my_answer = obj->cardsLeft(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string p0 = "AQK262362TKKAQ6262437892KTTJA332";
	CircleGame * obj = new CircleGame();
	clock_t start = clock();
	int my_answer = obj->cardsLeft(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 24;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
