#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,k,i;
    cin>>n>>k;
    vector<int> a(n);
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int count=0;
    int low=0,high=n-1,mid;
    for(i=0;i<n;i++)
    {
        low=i;
        high=n-1;
        if(a[n-1]-a[i]<k)
        {
            cout<<count;
            exit(0);
        }
        while(low<=high)
        {
            mid=(low+high)/2;
            int x=a[mid]-a[i];
            if(x==k)
            {
                count++;
                break;
            }
            else if(x<k)
                low=mid+1;
            else
                high=mid-1;
        }
    }
    cout<<count;
    return 0;
}
