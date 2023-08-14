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
class Solution {
public:
    ListNode* reverse(ListNode* node){
        ListNode* curr = node;
        ListNode* prev = NULL;
        ListNode* nextPtr;
        
        while(curr){
            nextPtr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextPtr;
        }
        
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // reverse the nodes
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        int rem = 0;
        ListNode* result = NULL;
        
        while(l1 || l2 || rem){
            int ans = rem;
            if(l1) {
                ans+= l1->val;
                l1 = l1->next;
            }
            if(l2) {
                ans+= l2->val;
                l2 = l2->next;
            }
            
            rem = ans/10;
            ans = ans%10;
            
            ListNode* newNode = new ListNode(ans);
            if(!result) result = newNode;
            else{
                newNode->next = result;
                result = newNode;
            }
        }
        
        return result;
    }
};