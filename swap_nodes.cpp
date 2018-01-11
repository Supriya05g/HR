#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct node {
    int data;
    struct node *left,*right;
}node;

node *newNode(int value)
{
    node *temp=(node *) malloc(sizeof(node));
    temp->data=value;
    temp->left=temp->right=NULL;
    return temp;
}

int main() {
    int n,c,alt=0,i,j,arr[1025];
    // fill_n(arr,1025,-1);
    // arr[0]=0;
    // arr[1]=1;
    cin>>n;
    node *cur,*parent;
    queue<node *> q;
    for(i=0;i<2*n;i++)
    {
        cin>>val;
        if(val!=-1)
        {
            cur=newNode(val);
            q.push(cur);
            parent=q.pop();
            if(alt==0)
            {
                q.left=cur;
                alt=1;
            }
            else
            {
                q.right=cur;
                alt=0;
            }
        }    
    }
    int T,k;
    cin>>T;
    for(i=0;i<T;i++)
    {
        cin>>k;
        
    }
    return 0;
}
