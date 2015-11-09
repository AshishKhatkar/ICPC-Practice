#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
using namespace std;

class CheatCode {
public:
	vector <int> matches(string, vector <string>);
};

vector <int> CheatCode::matches(string keyPresses, vector <string> codes) {
	int len = keyPresses.length();
	int n = codes.size();
	vector<int> res;
	for(int i = 0; i < n; ++i) {
		int len1 = codes[i].size();
		for(int tmp = 0; tmp < len; ++tmp) {
			if(keyPresses[tmp] == codes[i][0]) {
				bool flag = true;
				int idx = tmp + 1;
				if(idx >= len) {
					flag = false;
				}
				for(int j = 1; j < len1 && idx < len;) {
					if(codes[i][j] == keyPresses[idx]) {
						idx++;
						j++;
					} else if(codes[i][j] != keyPresses[idx] && keyPresses[idx] != keyPresses[idx - 1]) {
						flag = false;
						break;
					} else if(codes[i][j] != keyPresses[idx]) {
						idx++;
					}
					if(idx == len && j != len1) {
						flag = false;
						break;
					}
				}
				if(flag) {
					res.push_back(i);
					break;
				}
			}
		}
	}
	return res;
}


double test0() {
	string p0 = "UUDDLRRLLRBASS";
	string t1[] = {"UUDDLRLRBA","UUDUDLRLRABABSS","DDUURLRLAB","UUDDLRLRBASS","UDLRRLLRBASS"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	CheatCode * obj = new CheatCode();
	clock_t start = clock();
	vector <int> my_answer = obj->matches(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = { 0,  3,  4 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
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
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string p0 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
	string t1[] = {"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	CheatCode * obj = new CheatCode();
	clock_t start = clock();
	vector <int> my_answer = obj->matches(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = { 0 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
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
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string p0 = "IDDQDDTSFHHALL";
	string t1[] = {"FHHALL", "FHSHH", "IDBEHOLDA", "IDBEHOLDI", "IDBEHOLDL",
 "IDBEHOLDR", "IDBEHOLDS", "IDBEHOLDV", "IDCHOPPERS", "IDCLEV",
 "IDCLIP", "IDDQD", "IDDT", "IDFA", "IDKFA", "IDMYPOS", "IDMUS"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	CheatCode * obj = new CheatCode();
	clock_t start = clock();
	vector <int> my_answer = obj->matches(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = { 0,  11 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
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
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string p0 = "AABBCCDDEEFFGGHHIIJJKKLLMMNNOOPPQQRRSSTTUUVVWWXXYY";
	string t1[] = {"ABCDE", "BCDEF", "CDEFG", "DEFGH", "EFGHI",
 "FGHIJ", "GHIJK", "HIJKL", "IJKLM", "JKLMN",
 "KLMNO", "LMNOP", "MNOPQ", "NOPQR", "OPQRS",
 "PQRST", "QRSTU", "RSTUV", "STUVW", "TUVWX",
 "UVWXY", "VWXYZ", "WXYZA", "XYZAB", "YZABC",
 "ZABCD"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	CheatCode * obj = new CheatCode();
	clock_t start = clock();
	vector <int> my_answer = obj->matches(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
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
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string p0 = "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHSJ";
	string t1[] = {"LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHSS", "LAKJDGSJKGLSDKHFKDFHDGHSDKKSJDHFHJGKDKLSLSLJKAHSJ",
 "LAKJDGSJKGLSDKHFKDFHDHHSDKKSJDHFHJGKDKLSLSLJKASSJ",  "AKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHSJ",
 "LAJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSLJKHHSJ",  "LAKDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHSJ",
 "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDFHJGKDKLSLSLJKAHS",   "KJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHSJ",
 "LAKJDGSJKGLSDKHFKDFHDHHSDKKSJDHFHJGKDKLLSLJKAHS",    "LAKGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHSJ",
 "LAKJDGJKGLSDKHFKDFHDGHHDKKSJDHFHJGKDKLSLSLJKAHS",    "LAKJDGJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHSJ",
 "LAKJDGSJKGLSDKHFKDFHGHHSDKKSJDHFHJGKDKLSLSLJKAHS",   "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSL",
 "LAKJDGSJKGLSDKHFDFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHS",   "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLJKAHSJ",
 "LAKJDGSJKGLSDHFKDFHDGHHSDKKSJDHFHJGKDKLSLSJKAHS",    "KGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSL",
 "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJHFHJGKDKLSLSLJKAHS",   "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDSLSLJKAHSJ",
 "LAKJDGSJKGLSDKHFKDFHDGHHSDKSJHFHJGKDKLSLSLJKAHS",    "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKKLSLSLJKAHSJ",
 "LAKJDGSJKGLSDKHFKFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHS",   "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGDKLSLSLJKAHSJ",
 "LAKJDGSJKGLSDKHFKDFHDGHHSDKSJHFHJGKDKLSLSLJKAHS",    "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJKDKLSLSLJKAHSJ",
 "LKJDGSJKGLSDKHFKDFHDGHHSDKKJDHFHJGKDKLSLSLJKAHS",    "AKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHS",
 "LAJDGSJKGLSDKHFKDFHDGHHSDKKSJDFHJGKDKLSLSLKAHS",     "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFGKDKLSLSLJKAHSJ",
 "LKJDGSJKLSDKHFKDFHDGHHSDKSJDHFHJGKDKLSLSLJKAHS",     "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHHJGKDKLSLSLJKAHSJ",
 "AKJDGSJKGLSDKFKDFHDGHHSSJDHFJGKDKLSLSLJKAHS",        "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDFHJGKDKLSLSLJKAHSJ",
 "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFJGKDKLSLSLJKAHS",   "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJHFHJGKDKLSLSLJKAHSJ",
 "LAKJDSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDLSLSLJKAHS",    "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSDHFHJGKDKLSLSLJKAHSJ",
 "LAKJDSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDLSLSLJKAHS",    "LAKJDGSJKGLSDKHFKDFHDGHHSDKKJDHFHJGKDKLSLSLJKAHSJ",
 "LAKJDGSJKGLSDKHFKDFHDHHSDKKSJDHFHJGKDKLSLSLJKAHS",   "LAKDGSJKGLSDKHFKDFHDGHHSDKSJDHFHJGKDKLSLSLJKAHSJ",
 "LAKJDGSJKGLSDKHFKDFHDGHHSDKSJDHFHJGKDKLSLSLJKAS",    "KJDGSJKGLSDKHFKDFHDGHSDKKSJDHFHJGKDKLSLSLJKAH",
 "LAKJDGSJKGLSDKHFKDFHDGHHDKKSJDHFHJGKDKLSLSLJKAHS",   "LAKDGSJKGLSDKFHDGHHSDKSJDHFHJGKDKLSLSLJKAHSJ",
 "LAKJDGSJKGLSKHFKDFHDHHSDKKSJDHFHJGKDKLSLSLJKAHS",    "LAKJDGSJKGLSDKHFKDFHDGHHSKKSJDHFHJGKDKLSLSLJKAHSJ",
 "LAKJDGSJGLSDKHFKDFHDGHHSDKKSJDFHJGKDKLSLSLJKAHS",    "LAKJDGSJKGLSDKHFKDFHDGHHDKKSJDHFHJGKDKLSLSLJKAHSJ"}
;
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	CheatCode * obj = new CheatCode();
	clock_t start = clock();
	vector <int> my_answer = obj->matches(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = { 1,  3,  7,  13,  17,  27,  43 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
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
	if (my_answer != p2) {
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
