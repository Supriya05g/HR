// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> list;
        
        getlist(root,list,0);
        
        reverse(list.begin(),list.end());
        return list;
    }
    
    void getlist(TreeNode* root,vector<vector<int>> &list,int cur_level){
        if(root==NULL)
            return;
        
        if(list.empty() || cur_level >list.size()-1)
            list.push_back(vector<int>());
        
        list[cur_level].push_back(root->val);
        
        getlist(root->left,list,cur_level+1);
        getlist(root->right,list,cur_level+1);
    }
};