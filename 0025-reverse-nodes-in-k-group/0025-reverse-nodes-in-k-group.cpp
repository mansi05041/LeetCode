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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1) return head;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* curr=dummy;
        ListNode* prev=dummy;
        ListNode* next_ptr=dummy;
        int count=0;
        // count the total nodes
        while(curr){
            curr=curr->next;
            count++;
        }
        int to=0;
        while(next_ptr && to!=-1){
            curr=prev->next;
            next_ptr=curr->next;
            to=count>k?k:-1;
            for(int i=1;i<to;i++){
                curr->next=next_ptr->next;
                next_ptr->next=prev->next;
                prev->next=next_ptr;
                next_ptr=curr->next;
            }
            prev=curr;
            count-=k;
        }
        return dummy->next;
    }
};