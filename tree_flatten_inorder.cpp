// https://leetcode.com/contest/weekly-contest-100/problems/increasing-order-search-tree/

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
    TreeNode *prev=NULL,*head=NULL;
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL) return NULL;
        
        increasingBST(root->left);
        if(prev!=NULL){
            root->left=NULL;
            prev->right=root;
        }
        if(head==NULL) head=root;
        prev=root;
        increasingBST(root->right);
        return head;
    }
};