class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // intialize the dp vector
        vector<int> dp(amount+1,-1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            int minCoins = INT_MAX;
            for(auto coin: coins){
                if(i-coin>=0 && dp[i-coin]!=-1){
                    minCoins = min(minCoins,dp[i-coin]+1);
                }
            }
            dp[i]=(minCoins==INT_MAX)?-1: minCoins;
        }
        return dp[amount];
    }
};