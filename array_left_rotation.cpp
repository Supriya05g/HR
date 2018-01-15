/*
    https://www.hackerrank.com/challenges/array-left-rotation/problem
    array-left-rotation
*/

#include <bits/stdc++.h>

using namespace std;

vector <int> leftRotation(vector <int> a, int d) {
    // Complete this function
    for(int i=0;i<d;i++)
    {
        a.push_back(a.front());
        a.erase(a.begin());

    }
    return a;

}

int main() {
    int n;
    int d;
    cin >> n >> d;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector <int> result = leftRotation(a, d);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}
