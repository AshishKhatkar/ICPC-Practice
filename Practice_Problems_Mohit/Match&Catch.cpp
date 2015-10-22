/*
Author : lifecodemohit
Problem : http://codeforces.com/problemset/problem/427/D
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

using namespace std;

#define MOD 						1000000007
#define ll 							long long 
#define si(a)						scanf("%d", &a)
#define ss(a)						scanf("%s", a)

struct trie {
	int cnt;
	struct trie * arr[27];
};

struct trie * add(struct trie * node, int pos, int last, char str[]) {
	
	if (node == NULL) {
		node = (struct trie *)malloc(sizeof(struct trie));
		node->cnt = 0;
		for (int i = 0; i <= 26; i++)
			node->arr[i] = NULL;
	}
	if (pos > last)
		return node;

	int val = str[pos] - 'a';
	node->arr[val] = add(node->arr[val], pos+1, last, str);
	node->arr[val]->cnt += 1;
	return node;
}

int check(struct trie * node, struct trie * node1, int pos, int last, char str[]) {
	
	if (node == NULL)
		return MOD;

	if (pos > last)
		return MOD;

	int val = str[pos] - 'a';

	if (node->arr[val] == NULL)
		return MOD;

	if (node->arr[val]->cnt == 1 && node1->arr[val]->cnt == 1)
		return min(pos+1, check(node->arr[val], node1->arr[val], pos+1, last, str));

	return check(node->arr[val], node1->arr[val], pos+1, last, str);
}

int main()
{
	struct trie * node = (struct trie *)malloc(sizeof(struct trie));
	node->cnt = 0;
	for (int i = 0; i <= 26; i++)
		node->arr[i] = NULL;

	struct trie * node1 = (struct trie *)malloc(sizeof(struct trie));
	node1->cnt = 0;
	for (int i = 0; i <= 26; i++)
		node1->arr[i] = NULL;

	char str[5010];
	scanf("%s", str);
	int slen = strlen(str);
	for (int i = slen-1; i >= 0; i--)
		add(node, i, slen-1, str);

	char str1[5010];
	scanf("%s", str1);
	int ans = MOD;
	int slen1 = strlen(str1);

	for (int i = slen1-1; i >= 0; i--)
		add(node1, i, slen1-1, str1);
	
	for (int i = slen1-1; i >= 0; i--) {
		ans = min(ans, check(node, node1, i, slen1-1, str1) - i);
	}

	printf("%d\n",(ans<=5000?ans:-1));
	return 0;
}