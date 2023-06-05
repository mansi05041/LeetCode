class Solution {
public:
    int getDiffX(vector<int>& a,vector<int>& b){
        return a[0]-b[0];
    }
    int getDiffY(vector<int>& a,vector<int>& b){
        return a[1]-b[1];
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int deltaX = getDiffX(coordinates[1],coordinates[0]);
        int deltaY = getDiffY(coordinates[1],coordinates[0]);
        
        for(int i=2;i<coordinates.size();i++){
            if(deltaY*getDiffX(coordinates[i],coordinates[0])!=deltaX*getDiffY(coordinates[i],coordinates[0])) return false;
        }
        
        return true;
    }
};