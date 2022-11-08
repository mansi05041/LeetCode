class Solution {
public:
    string makeGood(string s) {
        // implementation using stack
        stack<char> st;
        string result;
        for(auto x:s){
            if(!st.empty() && (st.top()+32==x || st.top()-32==x)){
                st.pop();
            }
            else{
                st.push(x);
            }
        }
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        // reverse the string
        reverse(result.begin(),result.end());

       return result;
    }
};