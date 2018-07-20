#include<bits/stdc++.h>

using namespace std;

int c;

void search(int n,int y,vector<int>&col,vector<int>&diag1,vector<int>&diag2){
	if(y==n){
		c++;
		return;
	}
	for(int x=0;x<n;x++){
		if(col[x] || diag1[x+y] || diag2[x-y+n-1])
			continue;
		col[x]=diag1[x+y]=diag2[x-y+n-1]=1;
		search(n,y+1,col,diag1,diag2);
		col[x]=diag1[x+y]=diag2[x-y+n-1]=0;
	}
}

int main(){
	int n;
    c=0;
	n=16;
	vector<int>col(n),diag1(2*n-1),diag2(2*n-1);
	search(n,0,col,diag1,diag2);
    cout<<c;
    return 0;
}