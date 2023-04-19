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
    int maxLen =0;
    void Solve(TreeNode* root,bool isLeft,int currentStep){
        // base case
        if(root==NULL) return;
        // update the maximum length
        maxLen=max(currentStep,maxLen);
        // if the direction is left
        if(isLeft){
            Solve(root->left,false,currentStep+1);
            // we can restart the new path
            Solve(root->right,true,1);
        }
        else{
            Solve(root->right,true,currentStep+1);
            // we can restart the new path
            Solve(root->left,false,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        // start with left
        Solve(root,true,0);
        // start with right
        Solve(root,false,0);
        return maxLen;
    }
};