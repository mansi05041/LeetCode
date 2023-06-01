//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    vector<int> rank,parent;
    public:
    // constructor
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    // function to find the ultimate pair
    int findUpair(int node){
        if(node==parent[node]) return node;
        return parent[node]= findUpair(parent[node]);
    }
    // function to apply union by rank
    void unionByRank(int u,int v){
        int ulp_u = findUpair(u);
        int ulp_v = findUpair(v);
        if(ulp_u == ulp_v) return; // if both have same ultimate parent
        if(rank[ulp_u]<rank[ulp_v]) parent[ulp_u] = ulp_v;
        else if(rank[ulp_v]<rank[ulp_u]) parent[ulp_v] = ulp_u;
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                auto wt = it[1];
                auto u = i;
                auto v = it[0];
                
                edges.push_back({wt,{u,v}});
            }
        }
        
        // sort the edges
        sort(edges.begin(),edges.end());
        
        // use the disjoint sets
        DisjointSet ds(V);
        
        int mstWT = 0;
        
        for(auto it: edges){
            auto wt = it.first;
            auto u = it.second.first;
            auto v = it.second.second;
            
            if(ds.findUpair(u)!=ds.findUpair(v)) {
                mstWT+= wt;
                ds.unionByRank(u,v);
            }
        }
        
        return mstWT;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends