// https://leetcode.com/contest/weekly-contest-104/problems/x-of-a-kind-in-a-deck-of-cards/

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> counts;
        
        for(auto ele: deck) counts[ele]++;
        int res=0;
        for(auto i: counts) res=__gcd(i.second,res);
        return res>1;
    }
};