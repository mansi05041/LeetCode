class Solution {
public:
    vector<int> TopologicalSort(vector<int> indegree, vector<int> graph[]){
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }
        
        vector<int> res;
        
        while(!q.empty()){
            auto node= q.front();
            q.pop();
            res.push_back(node);
            
            for(auto it: graph[node]){
                if(--indegree[it]==0) q.push(it);
            }
        }
        
        return res;
    }
    
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
    
        // change the group number for -1
        for(int i=0;i<group.size();i++){
            if(group[i]==-1){
                group[i] = m++;
            }
        }
        
        // form the item graph and group graph and calculate the indegrees
        vector<int> indegree_ele(n,0);
        vector<int> indegree_grp(m,0);
        vector<int> Igraph[n];
        vector<int> Ggraph[m];
        for(int i=0;i<n;i++){
            for(auto it: beforeItems[i]){
                Igraph[it].push_back(i);
                indegree_ele[i]++;
                
                // connect the group graph if the elements doesn't belong to the same group
                if(group[it]!=group[i]){
                    Ggraph[group[it]].push_back(group[i]);
                    indegree_grp[group[i]]++;
                }
            }
        }

        // perform topological sort
        vector<int> topoSort_ele = TopologicalSort(indegree_ele,Igraph);
        vector<int> topoSort_grp = TopologicalSort(indegree_grp,Ggraph);
        
        if(topoSort_ele.size()!=n || topoSort_grp.size()!=m) return{};
        
        unordered_map<int,vector<int>> mp;
        for(auto it: topoSort_ele){
            mp[group[it]].push_back(it);
        }
        
        vector<int> res;
        for(auto it: topoSort_grp){
            res.insert(res.end(),mp[it].begin(),mp[it].end());
        }
        
        return res;
    }
};