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
        vector<vector<int>> dp(n+1,vector<int>(goal+1,-1));
        
        return helper(n,goal,k,dp);
    }
};