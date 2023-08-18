class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        // adjacency list
        vector<int> adj[n];
        for(auto it: roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        // calculate indegree
        vector<int> indegree(n,0);
        for(auto it: roads){
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        
        int maxRank = INT_MIN;
        
        // iterate over the pairs of roads
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                
                int rank = indegree[i]+indegree[j];
                if (std::find(adj[i].begin(), adj[i].end(), j) != adj[i].end()) {
                    rank -= 1;
                }
        
                // update the max rank
                maxRank = max(maxRank,rank);
            }
        }
        
        return maxRank;
    }
};