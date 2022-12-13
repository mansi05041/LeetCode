class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int matrix_sum=0;
        int n=mat.size();
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(i==j || i+j==n-1) matrix_sum+=mat[i][j];
            }
        }
        return(matrix_sum);
    }
};