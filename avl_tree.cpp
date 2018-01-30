// https://www.hackerrank.com/challenges/self-balancing-tree/problem

/* Node is defined as : */

#include<iostream>
#include<algorithm>
// #include<stdio.h>
// #include<stdlib.h>
using namespace std;


typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; 

// int max(int a,int b)
// {
// 	return a>b?a:b;
// }

int height(node *root)
{
	if(root==NULL)
		return -1;
	return root->ht;
}

node * newNode(int value)
{
    node* temp= (node *) malloc(sizeof(node));
    temp->val=value;
    temp->left=temp->right=NULL;
    temp->ht=0;
    return temp;
}

int balance_factor(node *root)
{
	if(root==NULL)
		return -1;
	return height(root->left)-height(root->right);
}

node * rotate_left(node *y)
{
	node *x=y->right;
	node *z=x->left;

	x->left=y;
	y->right=z;

	y->ht=max(height(y->left),height(y->right))+1;
	x->ht=max(height(x->left),height(x->right))+1;
	return x;
}

node * rotate_right(node *y)
{
	node *x=y->left;
	node *z=x->right;

	x->right=y;
	y->left=z;

	y->ht=max(height(y->left),height(y->right))+1;
	x->ht=max(height(x->left),height(x->right))+1;
	return x;
}

node * insert(node * root, int value) {
	if(root==NULL)
	    return newNode(value);
	if(root->val>=value)
	{
	   root->left=insert(root->left,value);
	} 
	else
	{
	    root->right=insert(root->right,value);
	}
	root->ht=1+max(height(root->left),height(root->right));	
	if(balance_factor(root)>1 && value<=root->left->val)
		return rotate_right(root);
	if(balance_factor(root)>1 && value>root->left->val)
	{
		root->left=rotate_left(root->left);
		return rotate_right(root);
	}	
	if(balance_factor(root)<-1 && value>root->right->val)
		return rotate_left(root);
	if(balance_factor(root)<-1 && value<=root->right->val)
	{
		root->right=rotate_right(root->right);
		return rotate_left(root);
	}	


	return root;
}

void preOrder(node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
  node *root = NULL;
 
  /* Constructing tree given in the above figure */
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);
 
  /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
  */
 
  printf("Preorder traversal of the constructed AVL"
         " tree is \n");
  preOrder(root);
 
  return 0;
}