// https://www.hackerrank.com/challenges/components-in-graph/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct subset{
	int ele;
	int parent;
	int size;
	int rank;
}subset;

void create(subset *set,int ele){
	set->ele=ele;
	set->parent=ele;
	set->size=1;
	set->rank=0;
}


//Path compression
int find_parent(subset set[],int ele){
	if(set[ele].parent!=ele)
		set[ele].parent=find_parent(set,set[ele].parent);
	return set[ele].parent;
}


//Union by rank
void join(subset set[],int v1,int v2,int *max){

	int xroot = find_parent(set, v1);
	int yroot = find_parent(set, v2);
	if(xroot==yroot)
		return;
	if(set[xroot].rank>set[yroot].rank){
		set[xroot].size+=set[yroot].size;
		set[yroot].parent=xroot;
		if(*max<set[xroot].size)
			*max=set[xroot].size;
	}
	else if(set[yroot].rank>set[xroot].rank){
		set[yroot].size+=set[xroot].size;
		set[xroot].parent=yroot;
		if(*max<set[yroot].size)
			*max=set[yroot].size;
	}
	else{
		set[yroot].parent=xroot;
		set[xroot].rank++;
		set[xroot].size+=set[yroot].size;
		if(*max<set[xroot].size)
			*max=set[xroot].size;
	}

}

int main() {
	int n,v1,v2,i,j,size,parent,max=1,min;
	char type;
	cin>>n;
	min=2*n;
	subset *set=(subset *)malloc((2*n+1)*sizeof(subset));
	for(i=1;i<=2*n;i++)
		create(&set[i],i);


	for(i=0;i<n;i++){
		cin>>v1>>v2;
		join(set,v1,v2,&max);
	}
    for(i=1;i<2*n;i++){
        parent=find_parent(set,i);
        if(set[parent].size!=1 && min>set[parent].size)
            min=set[parent].size;
    }
	cout<<min<<"\t"<<max;
    return 0;
}