/*
    https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list/problem
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
#include<iostream>
using namespace std;
typedef struct Node
{
  int data;
  Node *next;
  Node *prev;
}Node;

Node* SortedInsert(Node *head,int data)
{
    // Complete this function
   // Do not write the main method. 
	Node *newNode=(Node *)malloc(sizeof(Node)),*temp,*prev;
	newNode->data=data;
	newNode->next=NULL;
    newNode->prev=NULL;
	if (head==NULL)
		return newNode;
	temp=head;
    if(head->data>data)
    {
        newNode->next=head;
        head->prev=newNode;
        head->next=NULL;
        return newNode;
    }
	while(temp!=NULL)
	{
		if(temp->data<=data)
		{
			prev=temp;
			temp=temp->next;
		}
		else
		{
                
			newNode->prev=temp->prev;
			prev->next=newNode;
			newNode->next=temp;
            temp->prev=newNode;
            return head;			
		}
	}
	prev->next=newNode;
	newNode->prev=prev;
	newNode->next=NULL;
	return head;
}
int main()
{
	int x,a[4]={2,1,4,3};
	Node *head=NULL,*temp;
	cout<<"Main\n";
	x=0;
	for(int i=0;i<4;i++)
	{
		head=SortedInsert(head,a[i]);
		x++;
		cout<<x<<":\t";
		temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<"\t";
			temp=temp->next;
		}

		cout<<"\n";
	}

}

