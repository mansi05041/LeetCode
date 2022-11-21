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
    vector<int> preorderTraversal(TreeNode* root) {
        // visit root first then left and right subtree
        vector<int> node;
        stack<TreeNode*> st;
        TreeNode* temp =root;
        
        if(temp==NULL) return{};
        // push the root into stack
        st.push(temp);
        while(!st.empty()){
            temp= st.top();
            node.push_back(temp->val);
            st.pop();
            
            // traverse to right subtree
            if(temp->right!=NULL){
                st.push(temp->right);
            }
            
            // traverse to left subtree
            if(temp->left!=NULL){
                st.push(temp->left);
            }
        }
        return node;
        
    }
};