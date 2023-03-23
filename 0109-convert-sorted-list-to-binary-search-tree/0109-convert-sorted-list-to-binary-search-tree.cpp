/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* MiddleNode(ListNode* head){
        ListNode* slow =head;
        ListNode* fast = head;
        ListNode* prev = head;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(prev!=NULL){
            prev->next = NULL; // break the link
        }
        return slow;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        // base condition 
        if(head==NULL) return NULL;
        
        // Find the middle node
        ListNode* mid = MiddleNode(head);
        
        // create root node with value as middle node
        TreeNode* root = new TreeNode(mid->val);
        
        if(head==mid) return root;
        
        // recursively call the sortedListToBST for leftsubtree and rightsubtree
        root->left= sortedListToBST(head);
        root->right= sortedListToBST(mid->next);
        
        return root;
    }
};