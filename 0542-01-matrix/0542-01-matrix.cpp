class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // using bfs
        int m = mat.size();
        int n = mat[0].size();
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) q.push({i,j});
                else mat[i][j]=-1;
            }
        }
        
        vector<int> row = {-1,0,0,1};
        vector<int> col = {0,-1,1,0};
        
        while(!q.empty()){
            auto r = q.front().first;
            auto c = q.front().second;
            q.pop();
            
            // explore all directions
            for(int i=0;i<4;i++){
                int nr = r+row[i];
                int nc = c+col[i];
                
                // if out of bound or having -1, then skip it
                if(nr<0 || nc<0 || nr>=m || nc>=n || mat[nr][nc]!=-1) continue;
                
                q.push({nr,nc});
                mat[nr][nc]=mat[r][c]+1;
            }
        }
        
        return mat;
    }
};