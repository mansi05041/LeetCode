class Solution {
public:
    bool solve(int pos,int sum, vector<vector<int>>& dp,vector<int>& nums){
        // base case
        if(sum==0) return true;
        if(pos==0) return sum==nums[0];
        // already solve the subproblem
        if(dp[pos][sum]!=-1) return dp[pos][sum]==0 ? false: true;
        
        // not pick
        bool notPick = solve(pos-1,sum,dp,nums);
        
        // pick
        bool pick = false;
        if(nums[pos]<=sum) pick = solve(pos-1,sum-nums[pos],dp,nums);
        
        dp[pos][sum] = (notPick || pick) ? 1:0;
        return (notPick || pick);
    }
    bool canPartition(vector<int>& nums) {
        int totalSum =0;
        for(auto it:nums) totalSum+=it;
        // if the total sum is odd then not possible
        if(totalSum%2!=0) return false;
        
        // dp vector for memorization
        int n = nums.size();
        int sum = totalSum/2;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        
        // call the function solve that gives the result
        return solve(n-1,sum,dp,nums);
    }
};