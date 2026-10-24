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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp=head->next;
        ListNode* prev=head;
        head=head->next;
       while(temp!=NULL){
        ListNode* nextnode=temp->next;
        if(nextnode==NULL || nextnode->next==NULL){
            temp->next=prev;
            prev->next=nextnode;
            break;
        }
        temp->next=prev;
        prev->next=nextnode->next;
        prev=nextnode;
        temp=prev->next;
       }
       return head;
    }
};