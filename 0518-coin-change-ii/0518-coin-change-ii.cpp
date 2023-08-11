class Solution {
public:
    int Recursion(int amt,int idx,vector<int>& coins,vector<vector<int>>& dp){
        
        // base cases
        
        // complete the target
        if(amt==0) return 1;
        
        // out of boundary
        if(idx<0) return 0;
        
        // problem is already solved
        if(dp[idx][amt]!=-1) return dp[idx][amt];
        
        // not take
        int notTake = Recursion(amt,idx-1,coins,dp);
        
        // take
        int take = 0;
        if(amt>=coins[idx]) take = Recursion(amt-coins[idx],idx,coins,dp);
        
        return (take+notTake);
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        
        // base case
        // amount = 0 , then at any index it gives 1
        for(int idx=0;idx<=n;idx++) dp[idx][0] = 1;
        
        for(int idx=1;idx<=n;idx++){
            for(int amt=1;amt<=amount;amt++){
                
                // not take
                int notTake = dp[idx-1][amt];
                int take = 0;
                if(amt>=coins[idx-1]) take = dp[idx][amt-coins[idx-1]];
                
                dp[idx][amt] = take+notTake;
            }
        }
        
        return dp[n][amount];
    }
};