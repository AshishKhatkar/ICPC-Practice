#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
using namespace std;

class PaternityTest {
public:
	vector <int> possibleFathers(string, string, vector <string>);
};

vector <int> PaternityTest::possibleFathers(string child, string mother, vector <string> men) {
	int len = child.size();
	set<int> res;
	for(int i = 0; i < (1 << len); ++i) {
		if(__builtin_popcount(i) == len / 2) {
			//match following char of child with mother
			vector<char> v, v1;
			for(int j = 0; j < len; ++j) {
				if(i & (1 << j)) {
					v.push_back(j);
				} else {
					v1.push_back(j);
				}
			}
			bool matched_m = true;
			for(int j = 0; j < len / 2; ++j) {
				if(child[v[j]] != mother[v[j]]) {
					matched_m = false;
				}
			}
			if(matched_m) {
				for(int j = 0; j < (int)(men.size()); ++j) {
					bool matched_f = true;
					for(int k = 0; k < len / 2; ++k) {
						if(child[v1[k]] != men[j][v1[k]]) {
							matched_f = false;
						}
					}
					if(matched_f) {
						res.insert(j);
					}
				}
			}
		}
	}
	vector<int> final_res;
	set<int>::iterator it;
	for(it = res.begin(); it != res.end(); ++it) {
		final_res.push_back((*it));
	}
	return final_res;
}


double test0() {
	string p0 = "ABCD";
	string p1 = "AXCY";
	string t2[] = { "SBTD", "QRCD" };
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	PaternityTest * obj = new PaternityTest();
	clock_t start = clock();
	vector <int> my_answer = obj->possibleFathers(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = { 0 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string p0 = "ABCD";
	string p1 = "ABCX";
	string t2[] = { "ABCY", "ASTD", "QBCD" } ;
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	PaternityTest * obj = new PaternityTest();
	clock_t start = clock();
	vector <int> my_answer = obj->possibleFathers(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = { 1,  2 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string p0 = "ABABAB";
	string p1 = "ABABAB";
	string t2[] = { "ABABAB", "ABABCC", "ABCCDD", "CCDDEE" };
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	PaternityTest * obj = new PaternityTest();
	clock_t start = clock();
	vector <int> my_answer = obj->possibleFathers(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = { 0,  1 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string p0 = "YZGLSYQT";
	string p1 = "YUQRWYQT";
	string t2[] = {"YZQLDPWT", "BZELSWQM", "OZGPSFKT", "GZTKFYQT", "WQJLSMQT"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	PaternityTest * obj = new PaternityTest();
	clock_t start = clock();
	vector <int> my_answer = obj->possibleFathers(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	vector <int> p3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string p0 = "WXETPYCHUWSQEMKKYNVP";
	string p1 = "AXQTUQVAUOSQEEKCYNVP";
	string t2[] = { "WNELPYCHXWXPCMNKDDXD",
  "WFEEPYCHFWDNPMKKALIW",
  "WSEFPYCHEWEFGMPKIQCK",
  "WAEXPYCHAWEQXMSKYARN",
  "WKEXPYCHYWLLFMGKKFBB" };
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	PaternityTest * obj = new PaternityTest();
	clock_t start = clock();
	vector <int> my_answer = obj->possibleFathers(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = { 1,  3 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p3) {
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
