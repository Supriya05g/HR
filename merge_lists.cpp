/*

https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/problem

  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method
/*    Node *temp,*current,*next;
    if(headA==NULL)
        return headB;
    if(headB==NULL)
        return headA;
    if(headA->data>=headB->data)
    {
        temp=headB;
        headB=headA;
        headA=temp;
    }
    temp=headB;
    current=headA;
    while(temp!=NULL)
    {
        if(current->next==NULL)
        {
            current->next=temp;
            return headA;
        }
        if(current->next->data>=temp->data)
        {
            next=current->next;
            current->next=temp;
            current->next->next=next;
            temp=temp->next;
        }
        else
        {
            current=current->next;
        }
    }
    return headA;
    */
    Node *temp,*head;
    if(headA==NULL)
        return headB;
    if(headB==NULL)
        return headA;
    if(headA->data<=headB->data)
        {
            head=headA;
            headA=headA->next;
        }
    else
        {
            head=headB;
            headB=headB->next;      
        }
    temp=head;
    while(headA!=NULL || headB!=NULL)
    {
        if(headA==NULL)
        {
            temp->next=headB;
            break;
        }
        if(headB==NULL)
        {
            temp->next=headA;
            break;
        }    
        if(headA->data<=headB->data)
        {
            temp->next=headA;
            headA=headA->next;
            
        }
        else
        {
            temp->next=headB;
            headB=headB->next;      
        }
        temp=temp->next;
    }
    return head;
}
