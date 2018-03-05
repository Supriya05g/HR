// https://www.hackerrank.com/challenges/s10-basic-statistics/problem

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
// #include<cstudio>
#include<map>
#include<iomanip>

using namespace std;

int main()
{
	int n,i,ele,mod,max=0;
	long int sum=0;
	float mean,median;
	map<int,int> mode;
	cin>>n;
	vector<int> arr;
	for(i=0;i<n;i++)
	{
		cin>>ele;
		arr.push_back(ele);
		sum+=ele;
		if(mode.find(ele)==mode.end())
		{
			mode[ele]=1;
		}
		else
		{
			mode[ele]++;
		}
        if(mode[ele]>max)
        {
            max=mode[ele];
            mod=ele;
        }
        else if(mode[ele]==max && ele<mod)
        {
            mod=ele;
        }
	}
    // cout<<
	mean=float(sum)/n;
	cout<<setprecision(1)<<fixed<<mean<<endl;
	sort(arr.begin(),arr.end());
	if(n%2==0)
	{
		median=(arr[n/2-1]+arr[n/2])/2.0;
	}
	else
		median=arr[n/2];
	cout<<setprecision(1)<<median<<endl;

	cout<<mod;
	return 0;
}