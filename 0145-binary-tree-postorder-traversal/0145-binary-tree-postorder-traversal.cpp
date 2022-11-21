/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // left right root
        vector<int> node;
        stack<TreeNode*> st;
        
        // base case if root is null
        if(root==NULL) return{};
        
        TreeNode* temp=root;
        TreeNode* ptr;
        
        while(!st.empty() || temp!=NULL){
            // going to left
            if(temp!=NULL){
                st.push(temp);
                temp=temp->left;
            }
            else {
                ptr=st.top()->right;
            
            if(ptr==NULL){
                ptr=st.top();
                st.pop();
                node.push_back(ptr->val);
                while(!st.empty() && ptr==st.top()->right){
                    ptr=st.top();
                    st.pop();
                    node.push_back(ptr->val);
                }
           }
            else temp=ptr;
         }
       }
       return node;
    }
};