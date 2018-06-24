// https://github.com/keon/algorithms/blob/master/algorithms/dp/matrix_chain_order.py

#include<iostream>
#include<limits.h>
#define MAX 10000
using namespace std;

int mcm(int p[],int n){
	int m[n][n];

	for(int i=1;i<n;i++)
		m[i][i]=0;
    int j;
	for(int l=2;l<n;l++){
		for(int i=1;i<n-l+1;i++){
			j=i+l-1;
			m[i][j] = INT_MAX;
			for(int k=i;k<=j-1;k++){
				int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j])
					m[i][j]=q;
			}
		}
	}
	return m[1][n-1];

}

int main(){
	int n;
	cin>>n;
	int p[n];
	for(int i=0;i<n;i++)
		cin>>p[i];

	cout<<mcm(p,n)<<endl;
}