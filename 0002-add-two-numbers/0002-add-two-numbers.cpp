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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1=l1;
        ListNode* t2=l2;
        ListNode* head=NULL;
        ListNode* curr=NULL;
        int carry=0;
        while(t1!=NULL && t2!=NULL){
            int sum=t1->val+t2->val;
           sum=sum+carry;
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
                ListNode* newnode=new ListNode(sum);
                curr->next=newnode;
                curr=newnode;
            }
            t1=t1->next;
            t2=t2->next;
        }
        while(t1!=NULL){
            int sum=t1->val+carry;
            if(sum<10){
                carry=0;
            }
            else{
                carry=1;
                sum=sum%10;
            }
             ListNode* newnode=new ListNode(sum);
                curr->next=newnode;
                curr=newnode;
                t1=t1->next;
        }
        while(t2!=NULL){
            int sum=t2->val+carry;
            if(sum<10){
                carry=0;
            }
            else{
                carry=1;
                sum=sum%10;
            }
             ListNode* newnode=new ListNode(sum);
                curr->next=newnode;
                curr=newnode;
                t2=t2->next;
        }
        if(carry){
              ListNode* newnode=new ListNode(carry);
                curr->next=newnode;
                curr=newnode;
        }
        return head;
    }
};