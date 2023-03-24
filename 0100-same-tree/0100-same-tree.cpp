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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // base condition: both are null
        if(p==NULL && q==NULL) return true;
        
        // either one of them is null
        if(p==NULL || q==NULL) return false;
        
        // both are not same
        if(p->val!=q->val) return false;
        
        return(isSameTree(p->right,q->right) && isSameTree(p->left,q->left));
    }
};