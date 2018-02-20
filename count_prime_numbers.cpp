#include<iostream>
#include<vector>

using namespace std;
int main()
{
	int x,i,j,count=0;
	cin>>x;
	vector<int> list;
	cout<<"Prime numbers are: \n";
	for(i=2;i<=x;i++)
	{
		bool prime=true;
		for(j=2;j*j<=i;j++)
			if(i%j==0)
			{
				prime=false;
				break;
			}
		if(prime)
		{
			cout<<i<<"\t";
			count++;
			list.push_back(i);
		}
	}
	cout<<"\nNumber of prime numbers are: "<<count;
}
