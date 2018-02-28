// https://www.hackerrank.com/challenges/jesse-and-cookies/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <unistd.h>

using namespace std;

long int min(vector<long int> &heap)
{
	return heap[0];
}
long int left(long int i)
{
	return 2*i+1;
}
long int right(long int i)
{
	return 2*i+2;
}

long int parent(long int i)
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
	long int size,temp,i;
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

void min_heapify(vector<long int> &heap,long int i)
{
	if(heap.size()==1)
    {
        // heap.pop_back();
		return;
    }
	long int smallest,size,l,r,temp;
	smallest=i;
	l=left(i);
	r=right(i);
	size=heap.size();
	if(l<size && heap[l]<heap[i])
		smallest=l;
	if(r<size && heap[r]<heap[smallest])
		smallest=r;
	if(smallest!=i)
	{
		temp=heap[smallest];
		heap[smallest]=heap[i];
		heap[i]=temp;
		min_heapify(heap,smallest);
	}
}


int main() {
	long int n,sweetness,i,count=0,new_sweet,ele;
	vector<long int> heap;
	cin>>n>>sweetness;
	while(cin>>ele)
		insert(heap,ele);
	while(1)
	{
		if(min(heap)<sweetness && heap.size()>1)
		{
			new_sweet=heap[0]+2*heap[1];
			heap[0]=heap.back();
			heap.pop_back();
			min_heapify(heap,0);
			heap[0]=heap.back();
			heap.pop_back();
            if(!heap.empty())
                min_heapify(heap,0);			
			insert(heap,new_sweet);
			count++;
		}
		else if(min(heap)>=sweetness)
			break;
		// else if(heap.size()==1)
        else 
		{
			cout<<"-1";
			return 0;
		}
	}
	cout<<count;

    return 0;
}
