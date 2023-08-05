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
    vector<TreeNode*> helper(int start,int end,map<pair<int,int>,vector<TreeNode*>>& dp){
        vector<TreeNode*> res;
        // base case
        if(start>end){
            // exceeds the boundary
            res.push_back(NULL);
            return res;
        }  
        
        // if the problem is already solved
        if(dp.find({start,end})!=dp.end()) return dp[{start,end}];
        
        // choose the root
        for(int i=start;i<=end;i++){
            // i the root
            // generate all the possible left subtrees
            vector<TreeNode*> left = helper(start,i-1,dp);
            // generate all the possible right subtrees
            vector<TreeNode*> right = helper(i+1,end,dp);
            
            // generate all the possible BST
            for(auto l: left){
                for(auto r: right){
                    TreeNode* root = new TreeNode(i,l,r);
                    res.push_back(root);
                }
            }
        }
        
        return dp[{start,end}] = res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        // dp {left,right} -> possible subtrees
        map<pair<int,int>,vector<TreeNode*>> dp;
        return helper(1,n,dp);
    }
};