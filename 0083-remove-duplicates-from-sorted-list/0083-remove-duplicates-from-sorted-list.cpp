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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=head;
        while(curr!=NULL){
            if(curr->val!=prev->val){
                prev->next=curr;
                prev=curr;
            }
            curr=curr->next;
        }
       if(prev!=curr) prev->next=NULL;
        return head;
    }
};