/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        // root left right
        vector<int> pre;
        stack<Node*> st;
        Node* temp=root;
        
        // if root is NULL
        if(temp==NULL) return{};
        
        // push the root into stack
        st.push(temp);
        
        while(!st.empty()){
            // first store the stack's top and pop it
            temp=st.top();
            st.pop();
            
            // push the value of temp into vector 
            pre.push_back(temp->val);
            
            vector<Node*>child=temp->children;
            for(int i=child.size()-1;i>=0;i--) st.push(child[i]);
            
        }
        
        return pre;
        
    }
};