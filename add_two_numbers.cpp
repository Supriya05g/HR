// https://leetcode.com/explore/interview/card/top-interview-questions-medium/107/linked-list/783/

// Numbers can be greater than 2^64.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *sum=(ListNode *)malloc(sizeof(ListNode)),*prev,*head;
        int s=0;
        sum->val=0;
        sum->next=NULL;
        head=sum;
        while(l1!=NULL || l2!=NULL){
            if(l1!=NULL){
                s+=l1->val;
                l1=l1->next;
            } 
            if(l2!=NULL) {
                s+=l2->val;
                l2=l2->next;
            }
            
            sum->val=s%10;
            s/=10;
            ListNode *temp=(ListNode *)malloc(sizeof(ListNode));
            temp->val=0;
            sum->next=temp;
            prev=sum;
            sum=sum->next;
        }
        if(s!=0) {
            sum->val=s;
            sum->next=NULL;
        }
        else{
            prev->next=NULL;
        }
        return head;
    }
};