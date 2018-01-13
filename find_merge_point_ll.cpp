/*
  https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/problem
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
//Shit solution
int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method.
    Node *temp=headA,*run=headB;
    while(temp!=NULL)
    {
        while(run!=NULL)
        {
            if(run==temp)
                return run->data;
            if(run->next!=NULL && run->next==temp)
                return temp->data;
            else
                run=run->next;
        }
        temp=temp->next;
        run=headB;
    }
    return run->data;
}

//Good solution
int FindMergeNode(Node *headA, Node *headB)
{
  Node *currentA=headA,*currentB=headB;
  while(currentA!=currentB)
  {
    if(currentA->next!=NULL)
      currentA=currentA->next;
    else
      currentA=headB;
    if(currentB->next!=NULL)
      currentB=currentB->next;
    else
      currentB=headA;
  }
  return currentA->data;
}
