class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st; // store the index
        vector<int> ans(temperatures.size());
        for(int i=0;i<temperatures.size();i++){
            if(st.empty()) st.push(i);
            else{
                while(st.size() && temperatures[i]>temperatures[st.top()]){
                    ans[st.top()]=i-st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return(ans);
    }
};