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
    void reorderList(ListNode* head) {
        if ((!head) || (!head->next) || (!head->next->next)) return; // Edge cases
        int size=0;
        stack<ListNode*> st;
        ListNode* ptr=head;
        while(ptr!=NULL){
            st.push(ptr);
            ptr=ptr->next;
            size++;
        }
        ptr=head;
       for(int i=0;i<size/2;i++){
            ListNode* ele=st.top();
            ele->next=ptr->next;
            ptr->next=ele;
            ptr=ptr->next->next;
            st.pop();
        }
        ptr->next=NULL;
        
    }
};