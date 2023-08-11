class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
    
        // optimized with hash map and dp
        unordered_map<int,int> dp;
        int len = 1;
        
        for(int ele: arr){
            int prevEle = dp.count(ele-difference) ? dp[ele-difference] : 0;
            dp[ele] = prevEle + 1;
            len = max(len,dp[ele]);
        }
        
        return len;
    }
};