/* you only have to complete the function given below.  
Node is defined as  
*/
typedef struct node
{
    int data;
    node* left;
    node* right;
}node;



void preOrder(node *root) 
{
    if(root==NULL)
        return;
    cout<<(root->data)<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void Inorder(node *root) 
{
    if(root==NULL)
        return;
    Inorder(root->left);
    cout<<(root->data)<<" ";
    Inorder(root->right);
}

void postOrder(node *root) 
{
    if(root==NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<(root->data)<<" ";
}

int height(node* root) {
    if(root==NULL)
        return -1;
    else 
        return (1+max(height(root->left),height(root->right)));
}

//Top view problem
/*
int depth(Node * root,int data)
{
    static int h=0; 
    if(root->data==data)
        return h;
    h++;
    if(root->data>=data)
        depth(root->left,data)
    else 
        depth(root->left,data)
}
*/
void topViewL(node * root)
{
    if(root==NULL)
        return;
    topViewL(root->left);
    cout<<root->data<<" ";
}
void topViewR(node * root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    topViewR(root->right);
    
}

void topView(node * root) {
    topViewL(root->left);
    cout<<root->data<<" ";
    topViewR(root->right);
}


//Level order traversal

void levelOrder(node * root) {
    queue<node *> q;
    node * front;
    if(root!=NULL)
        q.push(root);
    
    while(!q.empty())
    {
        cout<<(q.front())->data<<" ";
        front=q.front();
        if(front->left!=NULL)
            q.push(front->left);
        if(front->right!=NULL)
            q.push(front->right);
        q.pop();
    }
  
}

//BST node insertion

node * newNode(int value)
{
    node* temp= (node *) malloc(sizeof(node));
    temp->data=value;
    temp->left=temp->right=NULL;
    return temp;
}

node * insert(node * root, int value) {
   if(root==NULL)
        return newNode(value);
   if(root->data>=value)
   {
       root->left=insert(root->left,value);
   } 
    else
    {
        root->right=insert(root->right,value);
    }
   return root;
}

//Huffman decoding


void decode_huff(node * root,string s)
{
    int i;
    node *mroot=root;
    for(i=0;i<s.size();i++)
    {
        if(s[i]=='0')
            root=root->left;
        else
            root=root->right;
        if(root->data!='\0')
        {
            cout<<root->data;
            root=mroot;
        }
    }        
}

//Lowest common ancestor between v1 and v2


node *lca(node *root, int v1,int v2)
{
    node *nv1,*nv2;
    while(1)
    {
    	if(v1<(root->data) && v2<(root->data))
    		root=root->left;
    	else if(v1>(root->data) && v2>(root->data))
    		root=root->right;
    	else if(v1==root->data || v2==root->data || (v1>(root->data) && v2<(root->data)) || (v1<(root->data) && v2>(root->data)) )
    		return root;
    }
   
}

