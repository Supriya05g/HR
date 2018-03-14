// https://www.hackerrank.com/challenges/s10-least-square-regression-line/tutorial

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
	int n,ele;
	n=5;
	vector<int>math,stats;
	for(int i=0;i<n;i++){
		cin>>ele;
		math.push_back(ele);
		cin>>ele;
		stats.push_back(ele);
	}
	int sum_x=0,sum_y=0,sum_x2=0,sum_xy=0;
	float b,a,mean_x,mean_y,x,y;

	for(int i=0;i<n;i++){
		sum_x+=math[i];
		sum_y+=stats[i];
		sum_xy+=math[i]*stats[i];
		sum_x2=math[i]*math[i];
		cout<<math[i]<<"\t"<<stats[i]<<endl;
	}
	cout<<sum_x<<"\t"<<sum_y<<"\t"<<sum_xy<<"\t"<<sum_x2<<endl;
	b=((float )(n*sum_xy-sum_x*sum_y))/(n*sum_x2-sum_x*sum_x);
	cout<<b<<endl;
	mean_x=1.0*sum_x/n;
	mean_y=1.0*sum_y/n;

	a=mean_y-b*mean_x;
	cout<<a<<endl;
	x=80;
	y=a+b*80;
	cout<<setprecision(3)<<fixed<<y;
    return 0;
}
