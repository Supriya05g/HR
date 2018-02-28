// https://www.hackerrank.com/challenges/qheap1/problem

#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

long int min(vector<long int> &heap)
{
	return heap[0];
}
int left(int i)
{
	return 2*i+1;
}
int right(int i)
{
	return 2*i+2;
}

int parent(int i)
{
	return (i-1)/2;
}

void insert(vector<long int> &heap,long int ele)
{
	if(heap.empty())
	{
		heap.push_back(ele);
		return;
	}
	int i;
	long int temp;
	heap.push_back(ele);
	i=heap.size()-1;
	while(i!=0 && heap[parent(i)]>heap[i])
	{
		temp=heap[parent(i)];
		heap[parent(i)]=heap[i];
		heap[i]=temp;
		i=parent(i);
	}
}
void min_heapify(vector<long int> &heap, int i)
{
	long int temp;
	heap[i]=heap.back();
	heap.pop_back();
	if(heap.empty())
		return;
	int l,r,smallest;
	smallest=i;
	l=left(i);
	r=right(i);
	if(l<heap.size() && heap[l]<heap[i])
		smallest=l;
	if(r<heap.size() && heap[r]<heap[smallest])
		smallest=r;
	if(smallest!=i)
	{
		temp=heap[smallest];
		heap[smallest]=heap[i];
		heap[i]=temp;
		min_heapify(heap,smallest);	
	}
}

void delete_key(vector<long int> &heap,long int ele)
{
	int pos=find(heap.begin(),heap.end(),ele)-heap.begin();
	min_heapify(heap,pos);
}


int main()
{
	int q,inp;
	long int v;
	vector<long int> heap;
	cin>>q;
	for(long int i=0;i<q;i++)
	{
		cin>>inp;
		switch(inp)
		{
			case 1: cin>>v;
					insert(heap,v);
					break;
			case 2: cin>>v;
					delete_key(heap,v);
					break;
			case 3: cout<<min(heap)<<endl;
					break;
		}
	}
}