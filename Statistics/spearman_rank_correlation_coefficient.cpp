// https://www.hackerrank.com/challenges/s10-spearman-rank-correlation-coefficient/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
	int n,pos;
	cin>>n;
	float res,d_square=0;
	vector<float> a(n),b(n),p(n),q(n);
	vector<int> rank_x(n),rank_y(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	p=a;
	q=b;
	sort(p.begin(),p.end());
	sort(q.begin(),q.end());
    // for(int i=0;i<n;i++)
    //     cout<<p[i]<<"\t";
    // cout<<"\n";
	for(int i=0;i<n;i++){
		pos=find(a.begin(),a.end(),p[i])-a.begin();
		rank_x[pos]=i+1;
	}
    // for(int i=0;i<n;i++)
    //     cout<<rank_x[i]<<"\t";
	for(int i=0;i<n;i++){
		pos=find(b.begin(),b.end(),q[i])-b.begin();
		rank_y[pos]=i+1;
	}
	for(int i=0;i<n;i++){
		d_square+=(rank_x[i]-rank_y[i])*(rank_x[i]-rank_y[i]);
	}
	res=1-(6*d_square)/(n*(n*n-1));
	cout<<setprecision(3)<<fixed<<res;
    return 0;
}