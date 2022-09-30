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
    ListNode* reverselist(ListNode *head){
         // code 
        ListNode* dummy = NULL;
        while(head){
            ListNode* next=head->next;
            head->next=dummy;
            dummy=head;
            head=next;
        }
        return(dummy);
    }
    bool isPalindrome(ListNode* head) {
        
        // find the middle node
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
         
        // store the middle element
        ListNode* mid = slow;
        
        // reverse the linked list from middle 
        slow=reverselist(slow);
        
        // compare from first and last 
        fast=head;
        while(fast!=mid->next && slow!=mid->next){
           if(fast->val!=slow->val) return false;
          else {
            fast=fast->next;
            slow=slow->next;
         } 
        }
        return(true);
        
    }
};