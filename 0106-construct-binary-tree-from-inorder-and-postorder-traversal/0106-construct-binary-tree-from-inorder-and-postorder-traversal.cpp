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
    TreeNode* constructTree(vector<int> postorder,int start,int end,int& rootIndex,unordered_map<int,int>& mp){
        // base case 
        if(start>end) return NULL;
        
        // create root node 
        TreeNode* root = new TreeNode(postorder[rootIndex--]);
        
        // search the index of current root
        int index = mp[root->val];
        
        // recursively call construct for right tree
        root->right = constructTree(postorder,index+1,end,rootIndex,mp);
        
        // recursively call construct for left tree
        root->left = constructTree(postorder,start,index-1,rootIndex,mp);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // inorder : Left root right, postorder : Left right root
        
        // create a map to store the inorder sequence to find the index of any element
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int pindex = postorder.size()-1;
        return constructTree(postorder,0,inorder.size()-1,pindex,mp);
        
    }
};