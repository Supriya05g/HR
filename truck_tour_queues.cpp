// https://www.hackerrank.com/challenges/truck-tour/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

//Shite solution
/*
int main() {
	queue<vector<unsigned long int>> main,temp;
	unsigned long int n,petrol,distance,i,j,start=0,flag=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		vector<unsigned long int> segment;
		cin>>petrol>>distance;
		segment.push_back(petrol);
		segment.push_back(distance);
		main.push(segment);
	}
	vector<unsigned long int> part,front;
	
	for(j=0;j<n;j++)
	{
		start=j;
		temp=main;
		petrol=0;
		while(!temp.empty())
		{
			part=temp.front();
			petrol+=part[0];
			distance=part[1];
			if(distance>petrol)
			{
				break;
			}
			else
			{
				flag=1;
				petrol-=distance;
				temp.pop();
			}
		}
		if(flag==1)
		{
			cout<<start;
			break;
		}
		front=main.front();
		main.pop();
		main.push(front);
	}

    return 0;
}
*/

//Good Solution

int main()
{
	queue<vector <int> > path;
	int n,petrol,distance,start=0,passed,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		vector<int> v;
		cin>>petrol>>distance;
		v.push_back(petrol);
		v.push_back(distance);
		path.push(v);
	}
	passed=0;
	petrol=0;
	while(passed<n)
	{
		vector<int> v=path.front();
		petrol+=v[0];
		path.pop();
		if(petrol>=v[1])
		{
			passed+=1;
			petrol-=v[1];
		}
		else
		{
			start+=passed+1;
			passed=0;
			petrol=0;
		}
		path.push(v);
	}
	cout<<start;
}