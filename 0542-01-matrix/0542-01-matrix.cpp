class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // using bfs
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<vector<int>> dist(m,vector<int>(n));
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }
        
        vector<int> row = {-1,0,0,1};
        vector<int> col = {0,-1,1,0};
        
        while(!q.empty()){
            auto r = q.front().first.first;
            auto c = q.front().first.second;
            auto d = q.front().second;
            q.pop();
            
            dist[r][c] = d;
            
            // explore all directions
            for(int i=0;i<4;i++){
                int nr = r+row[i];
                int nc = c+col[i];
                
                // if out of bound and already visited
                if(nr<0 || nc<0 || nr>=m || nc>=n || visited[nr][nc]==1) continue;
                
                q.push({{nr,nc},d+1});
                visited[nr][nc]=1;
            }
        }
        
        return dist;
    }
};