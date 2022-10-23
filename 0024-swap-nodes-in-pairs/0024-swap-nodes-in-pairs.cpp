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
        // boundary case
        //if(head || head->next) return head;
        
        // create a dummy node for tracking head
        ListNode* dummy = new ListNode(-1);
        dummy->next=head; 
        
        // intialize counter for swapping
        ListNode* prev= dummy;
        ListNode* curr = head;
        
        // go through to the linked list
        while(curr && curr->next){
            
            // connect previous node with the next node of current node
            prev->next=curr->next;
            // connect current node with the next to next node
            curr->next=curr->next->next;
            // connect the next of previous node with current
            prev->next->next = curr;
            // update current and previous pointers
            curr=curr->next;
            prev=prev->next->next;
        }
        return(dummy->next);
        
    }
};