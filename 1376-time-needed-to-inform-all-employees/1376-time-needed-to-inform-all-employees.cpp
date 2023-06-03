class Solution {
public:
    int maxTime = INT_MIN;
    void DFS(vector<int> adj[], vector<int>& informTime, int emp,int time){
        // get the maxTime
        maxTime = max(maxTime,time);
        
        // iterate over the adjacent employees
        for(auto it: adj[emp]){
            // visit the employees who get the information
            DFS(adj,informTime,it,time+informTime[emp]);
        }
        
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // adjacency list
        vector<int> adj[n];
        
        // populate the adjacency list
        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);
            }
        }
        
        // Call the DFS function
        DFS(adj,informTime,headID,0);
        
        return maxTime;
    }
};