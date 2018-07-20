#include<bits/stdc++.h>

using namespace std;

void search(int n, vector<int>&permutation,vector<bool>&chosen) {
    if (permutation.size() == n) {
        for(int i=0;i<permutation.size();i++)
            cout<<permutation[i]<<" ";
        cout<<endl;
        return;
    } 
    for (int i = 0; i < n; i++) {
        if (chosen[i]) continue;
        chosen[i] = true;
        permutation.push_back(i);
        search(n,permutation,chosen);
        chosen[i] = false;
        permutation.pop_back();
    }
}

int main(){
    vector<int> permutation;
    vector<bool> chosen(3,false);
    search(3,permutation,chosen);
    return 0;
}