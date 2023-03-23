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
    int ans=0;
    void DepthFirstSearch(TreeNode* root, int val){
        // base condition
        if(root==NULL) return;
        
        // left shift the val and add root value to it
        val*=10;
        val+=root->val;
        
        // if it is leaf node update the answer
        if(root->left==NULL && root->right==NULL){
            ans+=val;
            return;
        }
        
        // recursively call DepthSearch for left and right subtree
        DepthFirstSearch(root->left,val);
        DepthFirstSearch(root->right,val);
        
    }
    int sumNumbers(TreeNode* root) {
        // base condition
        if(root==NULL) return 0;
        DepthFirstSearch(root,0);
        return ans;
    }
};