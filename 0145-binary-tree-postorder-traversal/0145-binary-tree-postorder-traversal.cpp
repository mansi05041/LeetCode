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
        vector<int> res;
    stack<TreeNode*> st;

    if (!root) { // if root is NULL
        return res;
    }

    st.push(root); // push root onto the stack

    while (!st.empty()) {
        TreeNode* curr = st.top();
        st.pop();
        res.insert(res.begin(), curr->val); // insert current node's value at the beginning of the result vector

        if (curr->left) { // if current node has a left child, push it onto the stack
            st.push(curr->left);
        }

        if (curr->right) { // if current node has a right child, push it onto the stack
            st.push(curr->right);
        }
    }

    return res;
    }
};