/*The logic is if there are n numbers, there are 2^n subsets(including null set). So we iterate through 0 to 2^n. In each iteration b
, add all the numbers at positions where the bit was set in b to the subset. For example, add if we are iterating with b=6, then add elements in position
2 and 3 from array to the subset.
Let a={5,8,9,7};
If b=10
that iteration would add {8,7} as 10 in d = 1010 in b.
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n=4;
    int arr[4]={5,8,7,4};
    for (int b = 0; b < (1<<n); b++) {
        cout<<"Iteration "<<b<<"\n";
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            if (b&(1<<i)){
                subset.push_back(i);
                cout<<arr[i]<<" ";
            } 
        }
        cout<<"\n";
    }
}