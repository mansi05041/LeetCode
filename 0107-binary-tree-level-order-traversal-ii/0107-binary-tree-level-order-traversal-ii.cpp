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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // base condition
        if(root==NULL) return {};
        vector<vector<int>> ans;
        int n;
        queue<TreeNode*> qnode;
        qnode.push(root);
        while(!qnode.empty()){
            n = qnode.size();
            vector<int> temp;
            while(n--){
                auto node = qnode.front();
                qnode.pop();
                temp.push_back(node->val);
                if(node->left) qnode.push(node->left);
                if(node->right) qnode.push(node->right);
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};