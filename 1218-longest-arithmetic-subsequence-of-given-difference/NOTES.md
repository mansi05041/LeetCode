```
int longestSubsequence(vector<int>& arr, int difference) {
// this brute force will work only for positive numbers
set<int> st;
for(auto it: arr) st.insert(it);
int maxLen = INT_MIN;
for(int i=0;i<arr.size();i++){
int len = 1;
if(st.find(arr[i]-difference)==st.end()){
// find the element
int ele = arr[i]+difference;
while(st.find(ele)!=st.end()){
len++;
ele +=difference;
}
// update the max length
maxLen = max(maxLen,len);
}
}
return maxLen;
}
```