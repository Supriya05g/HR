// https://www.hackerrank.com/challenges/s10-multiple-linear-regression/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

vector<vector<float>> multiply(vector<vector<float> >&a,vector<vector<float>>&b){
	vector<vector<float>>c(a.size(),vector<float>(b[0].size()));
	for(int i=0;i<a.size();i++)
		for(int j=0;j<b[0].size();j++)
			c[i][j]=0;
	for(int i=0;i<a.size();i++)
		for(int j=0;j<b[0].size();j++)
			for(int k=0;k<a[0].size();k++)
				c[i][j]+=a[i][k]*b[k][j];
	return c;
}

void cofactor(vector<vector<float>>&a,vector<vector<float>>&temp,int p,int q,int n){
	int i=0,j=0;
	for(int row=0;row<n;row++){
		for(int col=0;col<n;col++){
			if(row!=p && col!=q){
				temp[i][j++]=a[row][col];
				if(j==n-1){
					j=0;
					i++;
				}
			}
		}
	}
}

float det(vector<vector <float>>&a,int n){

	if(n==1)
		return a[0][0];
	vector<vector<float>>temp(n,vector<float>(n));
	float D=0;
	int sign=1;
	for(int i=0;i<n;i++){
		cofactor(a,temp,0,i,n);
		D+=sign*a[0][i]*det(temp,n-1);
		sign=-sign;
	}
	return D;
}

void adjoint(vector<vector<float>>&a,vector<vector<float>>&adj,int n){
	if(n==1){
		adj[0][0]=1;
		return;
	}
	
	vector<vector<float>>temp(n,vector<float>(n));
	int sign=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cofactor(a,temp,i,j,n);
            // cout<<"Adjoint "<<i<<" "<<j<<endl;
            sign = ((i+j)%2==0)? 1: -1;
			adj[j][i]=sign*det(temp,n-1);
		}
	}
}

bool inverse(vector<vector<float>>&a,vector<vector<float>>&inv,int n){
	
	vector<vector<float>> adj(n,vector<float>(n));
	float D;
	D=det(a,n);
    // cout<<D<<endl;
	if(D==0)
		return false;
	adjoint(a,adj,n);
    // cout<<"Adjoint done"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			inv[i][j]=adj[i][j]/D;
	}
	return true;
}

vector<vector<float>> transpose(vector<vector<float>>&a){
	int p,q;
	p=a.size();
	q=a[0].size();
	vector<vector<float>>b(q,vector<float>(p));
	for(int i=0;i<q;i++)
		for(int j=0;j<p;j++)
			b[i][j]=a[j][i];
	return b;
}

void display(vector<vector<float>>&a){
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[0].size();j++)
			cout<<a[i][j]<<"\t";
		cout<<endl;
	}
}

int main() {
	int m,n,i,j;
	cin>>m>>n;
	vector<vector<float>>X(n,vector<float>(m+1)) ,Xt(m+1,vector<float>(n)),inv_XtX(m+1,vector<float>(m+1)),XtX(m+1,vector<float>(m+1)),Y(n,vector<float>(1));
	vector<vector<float>> B(m+1,vector<float>(1));
	for(i=0;i<n;i++){
		X[i][0]=1;
		for(j=1;j<=m;j++){
			cin>>X[i][j];
		}
		cin>>Y[i][0];
	}
	XtX=multiply(Xt,X);
	bool exist;
	exist=inverse(XtX,inv_XtX,m+1);
	if(!exist)
		return 0;
	vector<vector<float>>res(m+1,vector<float>(n));
	res=multiply(inv_XtX,Xt);
	B=multiply(res,Y);

    //Test values
	int x;
	cin>>x;
	vector<vector<float>> X_test(x,vector<float>(m+1)),Y_test(x,vector<float>(1));
	for(i=0;i<x;i++){
		X_test[i][0]=1;
		for(j=1;j<=m;j++)
			cin>>X_test[i][j];
	}
	Y=multiply(X_test,B);
	for(i=0;i<x;i++)
		cout<<setprecision(2)<<fixed<<Y[i][0]<<endl;
    return 1;
}