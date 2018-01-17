/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/
bool checkBT(Node * root,int min, int max)
{
    bool result;
    
	if(root==NULL)
		return true;
	result=checkBT(root->left,min,root->data);
	if(!result) return false;
	result=checkBT(root->right,root->data,max);
	if(!result) return false;

    if(root->data>=max ||root->data<=min )
        return false;			
        
	
	return true;


}
bool checkBST(Node* root) {
    return checkBT(root,0,10000);
}
