// https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/778/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hash;
        
        int i=0;
        for(auto s:strs){
            sort(s.begin(),s.end());
            hash[s].push_back(strs[i++]);
             
        }
        vector<vector<string>> ans;
        for(auto ele:hash){
            // sort(ele.second.begin(),ele.second.end());
            ans.push_back(ele.second);
            
        }
        return ans;
    }
};