/*
	Dynamic Array
	https://www.hackerrank.com/challenges/dynamic-array/problem
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX 10000
#define MAX_X 1000000000
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	vector<vector<unsigned long long> > seqList;
	unsigned long long x,y,i,n,q;
	int z,lastAnswer=0,seq_index;
	cin>>n>>q;
	for(i=0;i<n;i++)
		seqList.push_back(vector<unsigned long long>());
    // vector<vector<unsigned long int> > seqList(n, vector<unsigned long int>(q)); //Use this if you know the size of the array.   
	// cout<<"Enter values: \n";
	for(i=0;i<q;i++)
	{
		cin>>z>>x>>y;
		if(z==1)
		{
			seq_index=(x^lastAnswer)%n;
			// cout<<"Index is: "<<seq_index;
			seqList[seq_index].push_back(y);
			// cout<<seq_index<<" size:"<<seqList[seq_index].size()<<"\n";
			// cout<<"Contents are: ";
			// for (auto i = seqList[seq_index].begin(); i != seqList[seq_index].end(); ++i)
			//     cout << *i << ' ';
			// cout<<"\n";
		}
		else
		{
			seq_index=(x^lastAnswer)%n;
			lastAnswer=seqList[seq_index][y%(seqList[seq_index].size())];
			cout<<lastAnswer<<"\n";
		}
	}
    return 0;
}
