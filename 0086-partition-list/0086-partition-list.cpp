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
    ListNode* partition(ListNode* head, int x) {
        ListNode* gh=NULL,*lh=NULL,*great=NULL,*less=NULL;
        ListNode* temp=head;
        while(temp!=NULL){
            ListNode* nextnode=temp->next;
            if(temp->val<x){
                if(lh==NULL){
                    lh=temp;
                    less=temp;
                }
                else{
                    less->next=temp;
                    less=temp;
                }
            }
            else{
                if(gh==NULL){
                    gh=temp;
                    great=temp;
                }
                else{
                    great->next=temp;
                    great=temp;
                }
            }
            
            temp=nextnode;
        }
         if(less!=NULL) less->next=NULL;
        if(great!=NULL) great->next=NULL;
        ListNode* newhead=NULL;
       if(lh!=NULL){
        less->next=gh;
        return lh;
       }
        return gh;
    }
};