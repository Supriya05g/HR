/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int tailPos)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    /*
    Recursive way. Unsolved!
    if(head->next==NULL)
    {
        return 0;
    }
    pos=GetNode(head->next,tailPos);
    if(pos==tailPos)
    {
        pos++;
        return 
    }*/
    //Shit way to do it!
    int count=0;
    Node *temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
        
    tailPos=count-1-tailPos;
    while(tailPos--)
        head=head->next;
    return head->data;

    //Best way to do it.
    // int GetNode(Node *head,int positionFromTail)
    // {
    //     int index = 0;
    //     Node* current = head;
    //     Node* result = head;
    //     while(current!=NULL)
    //     {
    //         current=current->next;
    //         if (index++>positionFromTail)
    //         {
    //             result=result->next;
    //         }
    //     }
    //     return result->data;
    // }
}
