// https://www.hackerrank.com/challenges/no-prefix-set/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#define ALPHABET_SIZE 10
using namespace std;

typedef struct trie_node {
	struct trie_node *children[ALPHABET_SIZE]={NULL};
	bool is_end_of_word=false;
}trie_node;

trie_node *get_node()
{
	trie_node *node=new trie_node;
	return node;
}

void insert(trie_node *root,string key)
{
	trie_node *troot=root;
	int index;
	for(int i=0;i<key.length();i++)
	{	
		index=key[i]-'a';
		if(!troot->children[index])
			troot->children[index]=get_node();
		troot=troot->children[index];
		if(troot->is_end_of_word)
		{
			cout<<"BAD SET\n"<<key;
			exit(0);
		}
	}
	for(int i=0;i<ALPHABET_SIZE;i++)
	{
		if(troot->children[i])
		{
			cout<<"BAD SET\n"<<key;
			exit(0);
		}
	}
	troot->is_end_of_word=true;
}



int main() {
	int n;
	string key;
	trie_node *root=get_node();
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>key;
		insert(root,key);
	}
	cout<<"GOOD SET";
    return 0;
}
