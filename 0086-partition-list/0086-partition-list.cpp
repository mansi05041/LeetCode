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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* l1 = new ListNode(-1);
        ListNode* l2 = new ListNode(-1);
        
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        
        while(head){
            if(head->val<x){
                // append it to head1
                head1->next = head;
                head1 = head;
            }
            else{
                // append it to head2
                head2->next = head;
                head2 = head;
            }
            
            head = head->next;
        }
        
        // connect the both sublinked list
        head1->next = l2->next;
        head2->next = NULL;
        
        return l1->next;
    }
};