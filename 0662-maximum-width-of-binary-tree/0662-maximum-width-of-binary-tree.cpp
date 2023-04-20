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
    int widthOfBinaryTree(TreeNode* root) {
        // edge case
        if(root==NULL) return 0;
        
        // use queue to perform BFS
        queue<pair<TreeNode*,int>> q;
        
        // push the root into queue
        q.push({root,0});
        int result = 0;
        
        while(!q.empty()){
            int qSize = q.size();
            int startIdx = q.front().second;
            int endIdx = q.back().second;
            
            // update the result
            result = max(result,endIdx-startIdx+1);
            
            for(int i=0;i<qSize;i++){
                auto it = q.front().first;
                auto pos = q.front().second;
                
                // to avoid overflow
                int idx = pos-startIdx;
                q.pop(); // remove the node from queue
                
                // push the children of removed node
                if(it->left!=NULL) q.push({it->left,(long long)idx*(2)+1});
                if(it->right!=NULL) q.push({it->right,(long long)idx*(2)+2});
            }
        }
        
        return result;
    }
};