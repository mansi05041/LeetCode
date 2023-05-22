class Solution {
public:
    int minLength(string s) {
     // implement the stack
     stack<char> st;
     int i=0;
     while(i<s.size()){
         // push the current character in stack
         st.push(s[i]);
         while(!st.empty() && ((st.top()=='A' && s[i+1]=='B') || (st.top()=='C' && s[i+1]=='D'))){
             st.pop();
             i++;
         }
         i++;
     }
    return st.size();
    }
};
    