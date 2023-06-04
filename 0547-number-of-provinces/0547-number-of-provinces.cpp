class Solution {
public:
    void dfs(int i,vector<bool>& visited, vector<int> adj[],int n){
        // mark the city visited
        visited[i]=true;
        
        // iterate over all the adjacenct neighbors
        for(auto it: adj[i]){
            if(visited[it]==false){
                // call the dfs function
                dfs(it,visited,adj,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        
        // adjacency list
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(i==j)continue;
                if(isConnected[i][j]==1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        // visited array
        vector<bool> visited(n,false);
        
        // DFS traversal
        int province=0;
        for(int i=0;i<n;i++){
            // if the city is not visited
            if(visited[i]==false){
                province++;
                dfs(i,visited,adj,n);
            }
        }
        
        return province;
    }
};