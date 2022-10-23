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
    ListNode* swapPairs(ListNode* head) {
        
        // create a dummy node for tracking head
        ListNode* dummy = new ListNode(-1);
        dummy->next=head; 
        
        // intialize counter for swapping
        ListNode* prev= dummy;
        ListNode* curr = head;
        
        // go through to the linked list
        while(curr && curr->next){
            
            // save pointers
            ListNode* nextptr= curr->next->next;
            ListNode* second = curr->next;
            
            // swapping process
            second->next=curr;
            curr->next=nextptr;
            prev->next=second;
            
            // update pointers
            prev=curr;
            curr=nextptr;
        }
        return(dummy->next);
    }
};