//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    // Recursion function with memorization
    int solve(int W, int wt[], int val[], int index, vector<vector<int>>& dp){
        // base case
        if(index==0){
            if(wt[0]<=W) return val[0];
            else return 0;
        }
        
        // check if already present in the dp
        if(dp[index][W]!=-1) return dp[index][W];
        
        int notTaken= 0 + solve(W,wt,val,index-1,dp);
        int taken = INT_MIN;
        if(wt[index]<=W) taken = val[index]+ solve(W-wt[index],wt,val,index-1,dp);
        
        return dp[index][W]=max(notTaken,taken);
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n,vector<int>(W+1,-1));
       return solve(W,wt,val,n-1,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends