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
    TreeNode* ConstructBinaryTree(vector<int> preorder, unordered_map<int,int>& mp,int left,int right,int& root){
        if(left>right) return NULL;
        
        TreeNode* rootnode = new TreeNode(preorder[root]);
        // finding root in the map
        int idx = mp[rootnode->val];
        
        // next root
        root+=1;
        
        // recursively call the function for leftsubtree
        rootnode->left = ConstructBinaryTree(preorder,mp,left,idx-1,root);
        // recursively call the fucntion for rightsubtree
        rootnode->right = ConstructBinaryTree(preorder,mp,idx+1,right,root);
        
        return rootnode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // inorder : left root right
        // postorder : root right left
        
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int root = 0;
        int n = preorder.size();
        return ConstructBinaryTree(preorder,mp,0,n-1,root);
    }
};