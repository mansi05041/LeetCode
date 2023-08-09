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
    int minDepth(TreeNode* root) {   
        if(!root) return 0;
        
        // left child null 
        if(!root->left) return 1+minDepth(root->right);
        // right child null
        else if(!root->right) return 1+minDepth(root->left);
        
        // leaf node
        return 1+min(minDepth(root->right),minDepth(root->left));
     

    }
};