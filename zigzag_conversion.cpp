// https://leetcode.com/problems/zigzag-conversion/description/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        int skip=2*numRows-2;
        int inpos=0;
        int j=0;
        int n=s.length();
        string res="";
        while(inpos<numRows){
            j=inpos;
            while(j<n){
                if(j%skip==inpos || j%skip==skip-inpos)
                    res+=s[j];
                j++;
            }
            inpos++;
        }
        return res;
    }
};