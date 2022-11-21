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
    vector<int> inorderTraversal(TreeNode* root) {
        // using stack
        vector<int> node;
        stack<TreeNode*> st;
        TreeNode* temp = root;
        
        while(temp!=NULL || !st.empty()){
            // traverse to left
            while(temp!=NULL){
                st.push(temp);
                temp=temp->left;
            }
            temp=st.top();
            node.push_back(temp->val);
            st.pop();
            // traverse to right
            temp=temp->right;
        }
        
        return node;
    }
};