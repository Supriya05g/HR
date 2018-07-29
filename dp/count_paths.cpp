// https://www.geeksforgeeks.org/count-possible-paths-top-left-bottom-right-nxm-matrix/

#include<bits/stdc++.h>

using namespace std;

int count_paths(int n,int m){
	vector<vector<int>>paths(n,vector<int>(m));

	for(int i=0;i<n;i++)
		paths[i][0]=1;
	for(int i=0;i<m;i++)
		paths[0][i]=1;

	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			paths[i][j]=paths[i-1][j]+paths[i][j-1];
			cout<<paths[i][j]<<" ";
		}
		cout<<endl;
	}
	return paths[n-1][m-1];
}

int main(){
	cout<<count_paths(3,3)<<endl;
	return 0;
}