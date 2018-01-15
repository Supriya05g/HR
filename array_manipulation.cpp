/*
	Array manipulation
	https://www.hackerrank.com/challenges/crush/problem
*/

#include <bits/stdc++.h>
// #include<iostream>
using namespace std;
//Shit way. Works only for few test cases.
// int main() {
//     // int n;
//     int  m;
//     unsigned long long k,n,a,b,max=0;
//     cin >> n >> m;
//     vector<unsigned long long> list(n,0);
//     for(int i = 0; i < m; i++){
//         cin >> a >> b >> k;
//         for(;a<=b;a++)
//         {
//         	list[a-1]+=k;
//         	if(list[a-1]>max)
//         		max=list[a-1];
//         }
//     }
//     cout<<max;
    
//     return 0;
// }
//Good way

int main()
{
	long int n,k,m,a,b,x=0,max=0;
	cin>>n>>m;
	long int *p=new long int[n+1]();

	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>k;
		p[a]+=k;
		if(b+1<=n)
			p[b+1]-=k;
	}
	for(long int i=0;i<=n;i++)
	{
		x+=p[i];
		if(x>max)
			max=x;
	}
	cout<<max;
}