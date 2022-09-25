/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int count_node(ListNode *head){
        int count=0;
        ListNode *temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        return(count);
    }
    ListNode *_getIntesectionNode(int diff, ListNode *head1, ListNode *head2){
        ListNode* d1=head1;
        ListNode* d2=head2;
        while(diff>0){
            d1=d1->next;
            diff--;
        }
        while(d1 || d2){
            if(d1==d2) return(d2);
            d1=d1->next;
            d2=d2->next;
        }
        return(NULL);
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m=count_node(headA);
        int n=count_node(headB);
        int diff;
        if(n>m){
            diff=n-m;
            return _getIntesectionNode(diff, headB, headA);
        }
        else{
            diff=m-n;
             return _getIntesectionNode(diff, headA, headB);
        }
        return(NULL);
    }
};