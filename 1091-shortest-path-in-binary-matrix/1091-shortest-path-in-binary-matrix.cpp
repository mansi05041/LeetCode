class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        // base case
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        if(n==1) return 1; // source and destination is same
        
        // visited vector
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        
        // BFS traversal
        int len=0;
        queue<pair<int,int>> q;
        // push the source into queue, mark it visited and update the length
        q.push({0,0});
        visited[0][0]=true;
        
        
        while(!q.empty()){
            // increment the length
            len++;
            int size = q.size();
            
            while(size!=0){
                // remove the front node from queue
                auto i = q.front().first;
                auto j = q.front().second;
                q.pop();
                
                // explore all the eight directions
                vector<int> nextI = {1,1,1,0,-1,-1,-1,0};
                vector<int> nextJ = {1,-1,0,1,1,-1,0,-1};
                
                for(int k=0;k<8;k++){
                int nr = i+nextI[k];
                int nc = j+nextJ[k];
                
                if(nr>=0 && nr<n && nc>=0 && nc<n && visited[nr][nc]==false && grid[nr][nc]==0){
                    // check if it is the target node
                    if(nr==n-1 && nc==n-1) return len+1;
                    
                    // mark the current node visited
                    visited[nr][nc]=true;
                    // push the current node into queue
                    q.push({nr,nc});
                    }   
                }
                size--;
                
            }
            
        }
        return -1;
    }
};