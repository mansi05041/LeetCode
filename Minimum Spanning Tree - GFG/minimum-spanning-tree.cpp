//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        // using prims Algorithm
        
        // min heap that store the weight and node
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        // visited array 
        vector<bool> visited(V,false);
        
        // push the source node with intial weight
        pq.push({0,0});
        int sum=0;
        
        while(!pq.empty()){
            // remove the minimum weight node
            auto wt = pq.top().first;
            auto node = pq.top().second;
            pq.pop();
            
            // if the node is already visited then skip it
            if(visited[node]==true) continue;
            
            // not visited then add to sum and mark it visited
            visited[node]=true;
            sum+=wt;
            
            // iterate over neighbours
            for(auto it: adj[node]){
                // if the neighbor node is not visited then push into minheap
                if(visited[it[0]]==false) pq.push({it[1],it[0]});
            }
        }
        
        return sum;
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