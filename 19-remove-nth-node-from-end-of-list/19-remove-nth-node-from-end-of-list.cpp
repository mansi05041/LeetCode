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
    int count_node(ListNode* head){
        ListNode* temp=head;
        int count=0;
        while(temp){
            temp=temp->next;
            count++;
        }
        return(count);
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return(NULL);
        int total_nodes=count_node(head);
        int del = total_nodes-n;
        ListNode* res=head;
        if(del==0){
            // deletion at head
            head=head->next; 
            return(head);
        }
        ListNode* temp=head;
        while(del>1){
            temp=temp->next;
            del--;
        }
        if(temp->next->next==NULL){
            //res=temp->next;
            temp->next=NULL;
            return(head);
        }
        res=temp->next;
        temp->next=res->next;
        res->next=NULL;
        return(head);
    }
};