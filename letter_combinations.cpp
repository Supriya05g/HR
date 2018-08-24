// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> list;
        vector<string> res;
        char cur='a';
        int count;
        if(digits=="") return res;
        for(int i=0;i<=7;i++){
            if(i==5 || i==7)
                count=4;
            else count=3;
            int inc=0;
            list.push_back(vector<char>());
            while(count--){
                list[i].push_back(cur+inc);
                inc++;                
            }
            cur+=inc;
        }
        res.push_back("");
        for(int i=0;i<digits.length();i++){
            int num=digits[i]-'0';
            vector<string> temp;
            for(auto ele: res){
                for(auto c:list[num-2])
                    temp.push_back(ele+c);
            }
            res=temp;
        }
        return res;
    }
};