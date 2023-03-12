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
    ListNode* merge2Lists(ListNode* head1,ListNode* head2){
        ListNode* newHead = new ListNode(-1);
        ListNode* newTail = newHead;
        while(head1 && head2){
            if(head1->val<=head2->val){
                newTail->next = head1;
                head1=head1->next;
            }
            else{
                newTail->next = head2;
                head2 = head2->next;
            }
            newTail = newTail->next;
        }
        if(head1!=NULL){
            newTail->next=head1;
        }
        if(head2!=NULL){
            newTail->next=head2;
        }
        return(newHead->next);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        ListNode* mergeNode= lists[0];
        for(int i=1;i<lists.size();i++){
            mergeNode = merge2Lists(mergeNode,lists[i]);
        }
        return mergeNode;
    }
};