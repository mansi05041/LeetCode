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
    bool isCompleteTree(TreeNode* root) {
        
        // base case 
        if(root==NULL) return true;
        
        // use queue to store the children of root
        queue<TreeNode*> QNode;
        bool NotCompleteTree = false;
        QNode.push(root);
        
        while(!QNode.empty()){
            auto currNode = QNode.front();
            QNode.pop();
            
            // pushing left node 
            if(currNode->left){
                if(NotCompleteTree) return false;
                QNode.push(currNode->left);
            }
            else NotCompleteTree = true;
            
            // pushing right node
            if(currNode->right){
                if(NotCompleteTree) return false;
                QNode.push(currNode->right);
            }
            else NotCompleteTree = true;
        }
        
        return true;
        
    }
};