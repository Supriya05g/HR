/*
https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/problem
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    Node *temp=head,*run;
    if(head!=NULL && head->next!=NULL)
    {
        run=head->next->next;
    }
    else
        return false;
    while(temp!=NULL && run!=NULL)
    {
        if(run==temp)
            return true;
        else
        {
            temp=temp->next;
            if(run->next!=NULL)
                run=run->next->next;
            else
                return false;
        }
    }
    return false;
}
