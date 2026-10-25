/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* reverse(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* nextnode=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nextnode;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* a=reverse(l1);
        ListNode* b=reverse(l2);
      ListNode* h1=a;
      ListNode* h2=b;
      int carry=0;
      ListNode* head=NULL;
      ListNode* curr=NULL;
      while(h1!=NULL || h2!=NULL){
        int sum=0;
        if(h1){
            sum+=h1->val;
        }
        if(h2){
            sum+=h2->val;
        }
    sum+=carry;
    if(sum<10){
        carry=0;
    }
    else{
        carry=1;
        sum=sum%10;
    }
    if(head==NULL){
        head=new ListNode(sum);
        curr=head;
    }
    else{
        ListNode* x=new ListNode(sum);
        curr->next=x;
        curr=x;
    }
    if(h1){
        h1=h1->next;
    }
    if(h2){
        h2=h2->next;
    }
      }
      if(carry){
         if(head==NULL){
        head=new ListNode(carry);
        curr=head;
    }
    else{
        ListNode* x=new ListNode(carry);
        curr->next=x;
        curr=x;
    }
      }
      return reverse(head);
    }
};