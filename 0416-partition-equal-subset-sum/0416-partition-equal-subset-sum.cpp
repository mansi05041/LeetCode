class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum =0;
        for(auto it:nums) totalSum+=it;
        // if the total sum is odd then not possible
        if(totalSum%2!=0) return false;
        
        // dp vector for tabulation
        int n = nums.size();
        int sum = totalSum/2;
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        
        // base case
        for(int i=0;i<=n;i++) dp[i][0] = true; // sum is zero, then it is always possible
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                // if the current element is greater than the sum, exclude it
                if(nums[i-1]>j) dp[i][j]=dp[i-1][j];
                // otherwise include or exclude it
                else dp[i][j]= dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
        
        return dp[n][sum];
    }
};