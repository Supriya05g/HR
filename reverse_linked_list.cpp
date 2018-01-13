/*
	https://www.hackerrank.com/challenges/reverse-a-linked-list/problem
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
		prev=temp;
		temp=next;
	}
	return prev;
}