/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        // find the parent of every node
        unordered_map<TreeNode*,TreeNode*> mp;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            if(node->left){
                q.push(node->left);
                mp[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                mp[node->right] = node;
            }
        }
        
        vector<int> res;
        set<TreeNode*> visited;
        queue<pair<TreeNode*,int>> qb;
        
        qb.push({target,0});
        visited.insert(target);
        
        while(!qb.empty()){
            auto node = qb.front().first;
            auto d = qb.front().second;
            qb.pop();
            
            if(d==k){
                res.push_back(node->val);
            }
            
            // move to the parent
            if(mp[node] && visited.find(mp[node])==visited.end()){
                visited.insert(mp[node]);
                qb.push({mp[node],d+1});
            }
            
            // move to the left
            if(node->left && visited.find(node->left)==visited.end()){
                visited.insert(node->left);
                qb.push({node->left,d+1});
            }
            
            // move to the right
            if(node->right && visited.find(node->right)==visited.end()){
                visited.insert(node->right);
                qb.push({node->right,d+1});
            }
        }
        
        return res;
    }
};