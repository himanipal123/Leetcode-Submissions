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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
         vector<vector<int>> ans(m,vector<int>(n,-1));
         ListNode* temp=head;
         int rowstart=0,rowend=m-1;
         int colstart=0,colend=n-1;
         while(temp!=NULL && rowstart<=rowend && colstart<=colend){
            for(int j=rowstart;j<=colend;j++){
                if(temp==NULL){
                    break;
                }
                ans[rowstart][j]=temp->val;
                temp=temp->next;
            }
            rowstart++;
            for(int i=rowstart;i<=rowend;i++){
                                if(temp==NULL){
                    break;
                }
                 ans[i][colend]=temp->val;
                  temp=temp->next;
            }
            colend--;
            for(int j=colend;j>=colstart;j--){
                                if(temp==NULL){
                    break;
                }
                  ans[rowend][j]=temp->val;
                   temp=temp->next;
            }
            rowend--;
            for(int i=rowend;i>=rowstart;i--){
                                if(temp==NULL){
                    break;
                }
                 ans[i][colstart]=temp->val;
                  temp=temp->next;
            }
            colstart++;
         }
         return ans;
    }
};