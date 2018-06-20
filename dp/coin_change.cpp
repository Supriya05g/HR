// https://www.hackerrank.com/challenges/coin-change/problem

#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector <long> c(m);
    for (int i=0;i<m;i++) cin >> c[i];

    vector <long> numways(n+1); // numways[x] means # ways to get sum x
    numways[0]=1; // init base case n=0
    
    for (int i=0;i<m;i++) {
        for (int j=c[i];j<=n;j++) {
            numways[j]+=numways[j-c[i]]; 
	    // cout<<j<<'\t'<<numways[j]<<endl;
        }
	// cout<<"i= "<<i<<endl;
    }    

    cout << numways[n]<<endl;    
    return 0;
}



























