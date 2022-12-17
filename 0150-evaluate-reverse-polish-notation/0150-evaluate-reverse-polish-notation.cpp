class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        long a,b;
        for(auto i: tokens){
            if(i=="+"||i=="-"||i=="*"||i=="/"){
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
                if(i=="+") st.push(b+a);
                else if(i=="-") st.push(b-a);
                else if(i=="*") st.push(b*a);
                else st.push(b/a);  
            }
            else st.push(stol(i)); 
        }
        return(st.top());
    }
};