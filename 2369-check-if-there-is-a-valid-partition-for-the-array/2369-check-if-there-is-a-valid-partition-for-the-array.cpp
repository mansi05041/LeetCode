class Solution {
public:
    bool helper(vector<int>& nums,int idx,unordered_map<int,bool>& dp){
        
        // if the subproblem is already solved
        if(dp.count(idx)) return dp[idx];
        
        bool ans = false;
        
        // partition for two elements with same values
        if(idx>0 && nums[idx] == nums[idx-1]) 
            ans |= helper(nums,idx-2,dp);
        
        // partition for three elements with same values
        if(idx>1 && nums[idx] == nums[idx-1] && nums[idx-1] == nums[idx-2]) 
            ans |= helper(nums,idx-3,dp);
        
        // partition for three consecutive increasing elements
        if (idx > 1 && nums[idx] == nums[idx-1]+1 && nums[idx-1] == nums[idx-2]+1)
            ans |= helper(nums, idx-3, dp);
        
        return dp[idx] = ans;
    }
    
    bool validPartition(vector<int>& nums) {
        unordered_map<int,bool> dp;
        dp[-1] = true;
        return helper(nums,nums.size()-1,dp);
    }
};