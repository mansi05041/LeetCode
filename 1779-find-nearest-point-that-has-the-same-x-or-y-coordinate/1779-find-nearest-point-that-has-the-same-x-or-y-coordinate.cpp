class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int val=-1;
        int distance=INT_MAX;
        for(int i=0;i<points.size();i++){
            if(x!=points[i][0] && y!=points[i][1]) continue;
                if(distance>abs(points[i][0]-x)+abs(points[i][1]-y)){
                    val=i;
                    distance=abs(points[i][0]-x)+abs(points[i][1]-y);
                }
        }
        return val;
    }
};