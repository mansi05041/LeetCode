class Solution {
public:
    const int mod = pow(10,9)+7;
    long long helper(int n,int goal,int k,vector<vector<int>>& dp){
        // base case
        // empty playlist
        if(n==0 && goal==0) return 1;
        
        // zero unique songs or zero capacity of playlist
        if(n==0 || goal==0) return 0;
        
        // if the problem is already solved
        if(dp[n][goal]!=-1) return dp[n][goal];
        
        // two options: add a song or replay the song
        
        // add a song
        long long add = helper(n - 1, goal - 1, k, dp) * n;
        
        // replay a song
        long long replay = helper(n,goal-1,k,dp)* max(n-k,0);
        
        return dp[n][goal] = (add+replay)%mod;
    }
    
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long long>> dp(n+1,vector<long long>(goal+1,0));
        dp[0][0] = 1; // base case : empty playlist
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=goal;j++){
                // add a song
                long long add = dp[i-1][j-1]*i;
                long long replay = dp[i][j-1]*max(i-k,0);
                dp[i][j] = (add+replay)%mod;
            }
        }
        
        return dp[n][goal];
    }
};