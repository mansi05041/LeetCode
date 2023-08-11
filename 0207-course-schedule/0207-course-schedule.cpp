class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // calculate the indegree
        vector<int> indegree(numCourses,0);
        for(auto it:prerequisites){
            indegree[it[0]]++;
        }
        
        // adjacency list
        vector<int> adj[numCourses];
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        // queue to store the topological sort
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        int res = 0;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            res++;
            
            for(auto it: adj[node]){
                if(--indegree[it]==0) q.push(it);
            }
        }
        
        return res==numCourses;
    }
};