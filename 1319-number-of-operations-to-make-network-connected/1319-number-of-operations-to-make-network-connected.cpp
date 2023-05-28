class Solution {
public:
    void DFS(vector<vector<int>> &mp, vector<bool> &visited, int node){
        // mark the node visited
        visited[node]= true;
        for(auto it: mp[node]){
            if(visited[it]==false) DFS(mp,visited,it);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size()<n-1) return -1; // MST not satisfy
        // create the visited array 
        vector<bool> visited(n,false);
        
        // create the adjacency list
        vector<vector<int>> mp(n);
                
        for(auto &it: connections){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        
        // find the number of components using dfs
        int comp = 0;
        for(int i=0;i<n;i++){
            // check if it is not visited yet
            if(visited[i]==false){
                comp +=1;
                DFS(mp,visited,i);
            }
        }
        
        return comp-1;
    }
};