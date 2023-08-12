class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& grid,int m,int n,vector<vector<int>>& dp){
        // out of bound 
        if(i>=m || i<0 || j>=n || j<0) return 0;
        
        // blocked grid
        if(grid[i][j]==1) return 0;
        
        // reach the destination
        if(i==0 && j==0) return 1;
        
        // if the problem is already solved
        if(dp[i][j]!=-1) return dp[i][j];
        
        // explore the possible paths
        
        // top 
        int Top = helper(i-1,j,grid,m,n,dp);
        // left
        int Left = helper(i,j-1,grid,m,n,dp);
        
        return dp[i][j] = Top+Left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,obstacleGrid,m,n,dp);
    }
};