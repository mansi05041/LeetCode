class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // those nodes having zero outdegree are the safest
        // the node journey end at the terminal node are also safest
        
        // calculate the outdegree and get the reversed adjacency list
        int n = graph.size();
        vector<int> out(n);
        vector<int> adj[n];
        
        for(int i=0;i<n;i++){
            for(auto it: graph[i]){
                out[i]++;
                adj[it].push_back(i);
            }
        }
        
        queue<int> q;
        // push those nodes that have zero outdegree
        for(int i=0;i<n;i++){
            if(out[i]==0) q.push(i);
        }
        
        vector<int> safe(n,0);
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            safe[node]=1;
            
            for(auto it: adj[node]){
                if(--out[it]==0) q.push(it);
            }
        }
        
        vector<int> res;
        for(int i=0;i<n;i++){
            if(safe[i]==1) res.push_back(i);
        }
        
        return res;
    }
};