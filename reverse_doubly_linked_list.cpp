/*
	https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list/problem
	Reverse a linked list

  struct Node
  {
     int data;
     struct Node *next;
  }
*/

Node *Reverse(Node *head)
{
	Node *temp=head,*next,*prev;
	prev=NULL;
	while(temp!=NULL)
	{
		next=temp->next;
		temp->next=prev;
		temp->prev=next;
		prev=temp;
		temp=next;
	}
	return prev;
}