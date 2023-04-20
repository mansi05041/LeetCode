class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j=0;
        int N = pushed.size();
       for(auto i: pushed){
            // push the element into stack
           st.push(i);
           while(!st.empty() && j<N && st.top()==popped[j]){
               st.pop();
                j++;
           }   
       }        
        return j==N;
    }
};