// https://www.hackerrank.com/challenges/kangaroo/problem

#include <bits/stdc++.h>

using namespace std;

string kangaroo(int x1, int v1, int x2, int v2) {
    // Complete this function
    if(x1==x2 && v1!=v2){
        cout<<"NO"<<endl;
        exit(0);
    }
    else if(x1>x2 && v1>=v2){
        cout<<"NO"<<endl;
        exit(0);
    }
    else if(x1<x2 && v1<=v2){
        cout<<"NO"<<endl;
        exit(0);
    }
    int sum1=x1,sum2=x2;
    while(1){
        sum1+=v1;
        sum2+=v2;
        if(sum1==sum2){
        cout<<"YES"<<endl;
        exit(0);
        }
        else if(v1>=v2 && sum1>sum2){
        cout<<"NO"<<endl;
        exit(0);
        }
        else if(v1<=v2 && sum1<sum2){
        cout<<"NO"<<endl;
        exit(0);
        }
    }
        
}

int main() {
    int x1;
    int v1;
    int x2;
    int v2;
    cin >> x1 >> v1 >> x2 >> v2;
    string result = kangaroo(x1, v1, x2, v2);
    cout << result << endl;
    return 0;
}
