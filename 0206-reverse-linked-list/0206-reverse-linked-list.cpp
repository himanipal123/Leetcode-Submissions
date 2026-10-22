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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        stack<ListNode*>st;
        ListNode* temp=head;
        while(temp!=NULL){
            st.push(temp);
            temp=temp->next;
        }
        ListNode* newhead=NULL;
        ListNode* curr=NULL;
        while(!st.empty()){
            ListNode* x=st.top();
          st.pop();
            if(newhead==NULL){
                newhead=x;
                curr=newhead;
            }
            else{
                curr->next=x;
                curr=x;
            }
        }
        curr->next=NULL;
        return newhead;
    }
};