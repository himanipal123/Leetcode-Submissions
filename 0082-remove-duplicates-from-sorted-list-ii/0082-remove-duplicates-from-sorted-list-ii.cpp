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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        unordered_map<int,int>mp;
        ListNode* temp=head;
        while(temp!=NULL){
            mp[temp->val]++;
            temp=temp->next;
        }
        ListNode* newhead=NULL;
        ListNode* curr=NULL;
        temp=head;
        while(temp!=NULL){
            if(mp[temp->val]==1){
                if(newhead==NULL){
                    newhead=new ListNode(temp->val);
                    curr=newhead;
                }
                else{
                    ListNode* newnode=new ListNode(temp->val);
                    curr->next=newnode;
                    curr=newnode;
                }
            }
            temp=temp->next;
        }
        return newhead;
    }
};