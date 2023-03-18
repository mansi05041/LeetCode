class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        stack<int> st;
        int start=1;
        while(k!=0){
            if(find(arr.begin(),arr.end(), start)==arr.end()){
                // not found 
                st.push(start);
                k--;
            }
            start++;
        }
        return(st.top());
    }
};