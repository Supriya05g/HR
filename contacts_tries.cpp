// https://www.hackerrank.com/challenges/contacts/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <malloc.h>
#define ALPHABET_SIZE 26
using namespace std;

typedef struct trie_node {
	struct trie_node *children[ALPHABET_SIZE];
	bool is_end_of_word;
    int count=0;
}trie_node;

trie_node *get_node()
{
	trie_node *node=new trie_node;
	for(int i=0;i<ALPHABET_SIZE;i++)
		node->children[i]=NULL;
	node->is_end_of_word=false;
    return node;
}

void insert(trie_node *root,string key)
{
	trie_node *troot=root;
	int index;
	for(int i=0;i<key.length();i++)
	{
        troot->count++;
		index=key[i]-'a';
		if(!troot->children[index])
			troot->children[index]=get_node();
		troot=troot->children[index];
	}
	troot->is_end_of_word=true;
}

/*int find_count(trie_node *root)
{
	int count=0;
	trie_node *troot=root;
	for(int i=0;i<ALPHABET_SIZE;i++)
	{
		if(troot->children[i])
		{
			if(troot->children[i]->is_end_of_word)
				count++;
			count+=find_count(troot->children[i]);
            // cout<<count;
		}
	}
	return count;
}*/

bool search(trie_node *root,string key)
{
	trie_node *troot=root;
	int index;
	for(int i=0;i<key.length();i++)
	{
		index=key[i]-'a';
		if(!troot->children[index])
			return false;
		troot=troot->children[index];
	}
	if(troot==NULL)
		return false;
	int count=0;
	// if(troot->is_end_of_word)
	// count++;
	// count+=find_count(troot);
	cout<<troot->count<<endl;
	return true;
}

int main() {
	unsigned int n;
	bool present;
	string type,key,find,add;
	cin>>n;
	trie_node *root=get_node();
	for(unsigned int i=0;i<n;i++)
	{
		cin>>type>>key;
		if(type[0]=='a')
			insert(root,key);
		else
		{
			present=search(root,key);
            // cout<<present;
			if(!present)
				cout<<"0\n";
		}
	}
    return 0;
}
