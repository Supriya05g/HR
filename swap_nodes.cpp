// https://www.hackerrank.com/challenges/swap-nodes-algo/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct node{
	int data;
	struct node *left,*right;
}node;

node *newnode(int val){
	if(val==-1)
		return NULL;
	node *temp=(node *)malloc(sizeof(node));
	temp->data=val;
	temp->left=temp->right=NULL;
	return temp;
}

void inorder(node *root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int height(node *root){
	if(root==NULL)
		return -1;
	return 1+max(height(root->left),height(root->right));
}

/* void printq(queue<node *> q){
    while(!q.empty()){
        if(q.front()!=NULL)
            cout<<q.front()->data<<" ";
        else
            cout<<"NULL ";
        q.pop();
    }
    cout<<endl;
} 
*/
int main() {
	int n,l,r,t,k,cur;
	cin>>n;
	node *root=newnode(1),*temp,*swap;
	queue<node *>cur_q,next_q,q;
	q.push(root);
	for(int i=0;i<n;i++){
		cin>>l>>r;
        while(q.front()==NULL){
            q.pop();
        }
        temp=q.front();
        q.pop();
		temp->left=newnode(l);
		q.push(temp->left);
		temp->right=newnode(r);
		q.push(temp->right);
        // printq(q);
	}
    // cout<<"*****************";
	int hgt;
	hgt=height(root);
    // cout<<hgt<<endl;
	cin>>t;

	for(int i=0;i<t;i++){
		cin>>k;
		cur=1;
        cur_q={};
		cur_q.push(root);

		while(cur<=hgt){

            // printq(cur_q);
			while(!cur_q.empty()){
                temp=cur_q.front();
				if(cur%k==0 && cur_q.front()!=NULL){
					swap=temp->left;
					temp->left=temp->right;
					temp->right=swap;
				}
                if(temp!=NULL){
					next_q.push(temp->left);
					next_q.push(temp->right);
                }
                cur_q.pop();
			}
			cur++;
			cur_q=next_q;
			next_q={};

		}
		inorder(root);
		cout<<endl;
        // cout<<"*****************\n";
	}

    return 0;
}