// https://www.hackerrank.com/challenges/merging-communities/problem

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
void join(subset set[],int v1,int v2){

	int xroot = find_parent(set, v1);
	int yroot = find_parent(set, v2);
	if(xroot==yroot)
		return;
	if(set[xroot].rank>set[yroot].rank){
		set[xroot].size+=set[yroot].size;
		set[yroot].parent=xroot;
	}
	else if(set[yroot].rank>set[xroot].rank){
		set[yroot].size+=set[xroot].size;
		set[xroot].parent=yroot;
	}
	else{
		set[yroot].parent=xroot;
		set[xroot].rank++;
		set[xroot].size+=set[yroot].size;
	}

}

int main() {
	int n,q,v1,v2,i,j,size,parent;
	char type;
	cin>>n>>q;
	subset *set=(subset *)malloc((n+1)*sizeof(subset));
	for(i=1;i<=n;i++)
		create(&set[i],i);


	for(i=0;i<q;i++){
		cin>>type;
		if(type=='M'){
			cin>>v1>>v2;
			join(set,v1,v2);
		}
		else{
			cin>>v1;
			parent=find_parent(set,v1);
			cout<<set[parent].size<<endl;
		}
	}
    return 0;
}