// https://www.geeksforgeeks.org/check-characters-given-string-can-rearranged-form-palindrome/

#include<bits/stdc++.h>

using namespace std;

bool can_permute_string(string s){
    unordered_set<char> hash;
    for(int i=0;i<s.length();i++){
        if(hash.count(s[i]))
            hash.erase(s[i]);
        else
            hash.insert(s[i]);
    }
    
    return hash.size()<=1;
}
int main() {
    cout<<can_permute_string("carerac");    
}