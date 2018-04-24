// https://www.hackerrank.com/challenges/the-birthday-bar/problem

#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector < int > s, int d, int m){
    int i,j,count=0,sum=0,len;
    if(d<m)
        return 0;
    for(i=0;i<n;i++){
        sum=0;
        len=m;
        j=i;
        if(j<n-m+1)
        while(len-- && j<n){
            sum+=s[j];
            if(sum>d)
                break;
            j++;
        }
        if(sum==d)
            count++;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
    }
    int d;
    int m;
    cin >> d >> m;
    int result = solve(n, s, d, m);
    cout << result << endl;
    return 0;
}
