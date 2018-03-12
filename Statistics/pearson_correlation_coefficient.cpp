// https://www.hackerrank.com/challenges/s10-pearson-correlation-coefficient/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

float standard_deviation(float *a,int n,float mean){
	float sum=0,variance;
	for(int i=0;i<n;i++){
		sum+=a[i]*a[i];
	}
	variance=sum/n-mean*mean;
	return sqrt(variance);
}

int main() {
	int n;
	cin>>n;
	float a[n],b[n],sum,res=0,covar,std1,std2,mean1=0,mean2=0;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
		mean1+=a[i];
	}
	mean1/=n;
	
	for(int i=0;i<n;i++){
		cin>>b[i];
		mean2+=b[i];
	}
	mean2/=n;

	std1=standard_deviation(a,n,mean1);
	std2=standard_deviation(b,n,mean2);

	for(int i=0;i<n;i++){
		res+=(a[i]-mean1)*(b[i]-mean2);
	}
	res=res/(std1*std2*n);

	cout<<setprecision(3)<<fixed<<res;


    return 0;
}