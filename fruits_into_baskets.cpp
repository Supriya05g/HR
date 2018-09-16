// https://leetcode.com/contest/weekly-contest-102/problems/fruit-into-baskets/

class Solution {
public:
	int totalFruit(vector<int>& tree) {
		int recent=-1,old=-1,count=0,count_rec=0,maxcount=0;
		
		for(int i=0;i<tree.size();i++){
			count= (recent==tree[i] || old==tree[i])? count+1:count_rec+1;
			count_rec=(recent==tree[i]) ? count_rec+1:1;
			if(tree[i]!=recent) old=recent, recent=tree[i];
			maxcount=max(maxcount,count);
		}
		return maxcount;
	}
};