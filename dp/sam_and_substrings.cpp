// https://www.hackerrank.com/challenges/sam-and-substrings/problem

#include<iostream>
#include<stdio.h>
#include<string.h>
#define MOD 1000000007
using namespace std;

int main(){
	string s;
	long long int c=1,sum=0;

	cin>>s;
	for(int i=s.length();i>=1;i--){
		sum=(sum+(s[i-1]-'0')*c*i)%MOD;
		c=(c*10+1)%MOD;
	}

	cout<<sum<<endl;
	return 0;
}
