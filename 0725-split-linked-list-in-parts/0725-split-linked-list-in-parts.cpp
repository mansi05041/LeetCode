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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k,NULL);
        
        // count the nodes
        int count = 0;
        ListNode* curr = head;
        
        while(curr){
            count++;
            curr=curr->next;
        }
        
        // split the linked list
        int size = count/k;
        int extra = count%k;
        
        curr = head;
        
        for(int i=0;i<k && curr;i++){
            res[i]=curr;
            // find the tail
            for(int j=0;j<size+(extra>0?1:0)-1;j++) curr = curr->next;
            ListNode* temp = curr->next;
            curr->next = NULL;
            curr = temp;
            extra--;
        }
        
        return res;
    }
};