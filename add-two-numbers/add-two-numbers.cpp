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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      
        // create a dummy node which links the resulted linked list
        ListNode* dummy = new ListNode(0);
        ListNode* temp=dummy;
        int carry=0;
        while(l1 || l2 || carry){  // it will execute until all becomes false
            int sum=0;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;  // sum/10 gives the tens digit value
            ListNode* newnode = new ListNode(sum%10);  // sum%10 gives the unit digit value
            temp->next=newnode;
            temp=temp->next;
        }
        return(dummy->next);
        
    }
};