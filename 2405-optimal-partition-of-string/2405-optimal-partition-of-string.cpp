class Solution {
public:
    int partitionString(string s) {
        set<char> st;
        int count=0;
        for(int i=0;i<s.size();i++){
            // check if the current char present in the set or not
            if(st.find(s[i])!=st.end()){
                // present in the set
                count+=1;
                st.clear();
            }
            // add the current index in the set
            st.insert(s[i]);
        }
        count+=1; // for the last group
        return count;
    }
};