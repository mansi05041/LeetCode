//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {
            // code here          
            
            // indegree calculate
            vector<int> indegree(n+1,0);
            for(auto it: edges){
                indegree[it[1]]++;
            }
            
            // timer : that maintains the time of the each node
            vector<int> timer(n+1,0);
            
            // adj : adjacency list
            vector<vector<int>> adj(n+1);
            for(auto it: edges){
                adj[it[0]].push_back(it[1]);
            }
            
            // queue 'q': used for maintain the nodes having 0 indegree
            queue<int> q;
            // push those nodes having zero indegree and set the timer to 1
            for(int i=1;i<=n;i++){
                if(indegree[i]==0){
                    q.push(i);
                    timer[i]=1;
                }
            }
            
            while(!q.empty()){
                // remove the front node from queue
                auto node = q.front();
                q.pop();
                
                // iterate through its adjacent neighbors
                for(auto it: adj[node]){
                    // decrement the indegree
                    indegree[it]--;
                    // if the indegree of the node becomes zero then add to queue and update the timer
                    if(indegree[it]==0){
                        q.push(it);
                        timer[it]=timer[node]+1;
                    }
                }
                
            }
            
            return std::vector<int>(timer.begin()+1,timer.end());
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> edges(m,vector<int>(2));
        for(int i=0;i<m;i++)
            cin>>edges[i][0]>>edges[i][1];
        Solution s;
        vector<int> ans=s.minimumTime(n,edges,m);
        for(auto j:ans)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends