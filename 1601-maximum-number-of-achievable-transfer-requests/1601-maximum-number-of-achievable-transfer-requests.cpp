class Solution {
public:
    void helper(int idx,int n,vector<vector<int>>& req,vector<int>& indegree,int& ans,int count){
        // base case
        if(idx==req.size()){
            // check if all the indegree are zero
            for(int i=0;i<n;i++){
                if(indegree[i]!=0) return;
            }
            
            ans = max(ans,count);
            return;
        }
        
        indegree[req[idx][0]]--;
        indegree[req[idx][1]]++;
        
        helper(idx+1,n,req,indegree,ans,count+1);
        
        indegree[req[idx][0]]++;
        indegree[req[idx][1]]--;
        
        helper(idx+1,n,req,indegree,ans,count);
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int ans = 0;
        vector<int> indegree(n,0);
        helper(0,n,requests,indegree,ans,0);
        return ans;
    }
};