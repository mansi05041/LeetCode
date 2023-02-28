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
    
    // for merging the sorted two halves
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* head=NULL;
        ListNode* tail=NULL;
        
        // the resultant linked list have one node
        if(l1->val<=l2->val){
            head=tail=l1;
            l1=l1->next;
        }
        else{
            head=tail=l2;
            l2=l2->next;
        }
        
        while(l1 && l2){
            if(l1->val<=l2->val){
                tail->next=l1;
                l1=l1->next;
            }
            else{
                tail->next=l2;
                l2=l2->next;
            }
            tail=tail->next;
        }
        
        if(l1!=NULL){
            tail->next=l1;
        }
        
        if(l2!=NULL){
            tail->next=l2;
        }
        
        return head;
    }
    
    // for getting middle node
    ListNode* middleNode(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(slow->next && (fast&& fast->next)){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    ListNode* sortList(ListNode* head) {
        
        // implement the merge sort for this problem
        
        // base condition: if there is no or single node in the linked list
        if(head==NULL || head->next==NULL) return head;
        
        // find the middle node
        ListNode* middle = middleNode(head);
        
        // divide the linked list into half
        ListNode* head2 = middle->next;
        middle->next = NULL;
        
        // call the sortList() for the halves linked list
        ListNode* firstHalf = sortList(head);
        ListNode* secondHalf = sortList(head2);
        
        // call the merge() to merge the firstHalf and secondHalf linked list
        ListNode* newHead = merge(firstHalf,secondHalf);
        
        return newHead;
        
    }
};