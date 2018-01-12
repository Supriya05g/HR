/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method.
    Node *temp=head,*next;
    if(head->next==NULL)
        return head;
    next=head->next;
    while(temp->next!=NULL)
    {
        if(temp->data==next->data)
        {
            temp->next=next->next;
            next=temp->next;
        }
        else
        {
            temp=temp->next;
            next=temp->next;

        }
    }
        return head;
}
