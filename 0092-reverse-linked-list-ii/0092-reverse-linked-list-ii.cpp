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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<ListNode*>st;
        ListNode* temp=head;
        ListNode* newhead=NULL;
        ListNode* curr=NULL;
        int cnt=0;
        while(cnt<right){
            cnt++;
            if(cnt>=left){
                st.push(temp);
                 temp=temp->next;
                 continue;
            }
            if(newhead==NULL){
                newhead=temp;
                curr=newhead;
            }
            else{
                curr->next=temp;
                curr=temp;
            }
            temp=temp->next;
        }
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
            curr->next=temp;
       
        return newhead;
    }
};