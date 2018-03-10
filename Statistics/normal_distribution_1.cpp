// https://www.hackerrank.com/challenges/s10-normal-distribution-1/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;


int main() {
	float mean,std,x,inp1,y1,y2,res,inp;
	cin>>mean>>std;

	cin>>inp1;
    // cout<<erf(-0.5/2)<<endl;
	res=0.5*(1+erf((inp1-mean)/(std*sqrt(2))));
	cout<<setprecision(3)<<fixed<<res<<endl;

	cin>>y1>>y2;
	                 res=0.5*(erf((y2-mean)/(std*sqrt(2)))- erf((y1-mean)/(std*sqrt(2))));
	cout<<setprecision(3)<<fixed<<res;
    return 0;
}
