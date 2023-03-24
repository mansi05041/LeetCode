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
    bool checkSymmetric(TreeNode* left, TreeNode* right){
        // base condition
        if(left==NULL || right==NULL) return(left==right);
        
        // impose and check the value are same or not
        if(left->val!=right->val) return false;
        
        // recursively check for left and right subtree
        return(checkSymmetric(left->left,right->right) && checkSymmetric(left->right,right->left));
    }
    bool isSymmetric(TreeNode* root) {
        // base condition
        if(root==NULL) return true;
        return (checkSymmetric(root->left,root->right));
    }
};