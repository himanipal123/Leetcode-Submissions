/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
 
          Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }
    queue<Node*>qu;
    Node* temp=root;
    qu.push(temp);
        while(!qu.empty()){
           int n=qu.size();
           for(int i=0;i<n;i++){
             Node* x=qu.front();
            qu.pop();
            if(i==n-1){
                x->next=NULL;
            }
            else{
                x->next=qu.front();
            }
             if(x->left){
                qu.push(x->left);
            }
            if(x->right){
                qu.push(x->right);
            }
       
           }
           
        }
    
    return root;
    }
};