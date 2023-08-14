class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        // base case
        if(intervals.size()==0) return 0;
        
        // sort the intervals according to start time
        sort(intervals.begin(),intervals.end());
        
        int count = 0;
        int last=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[last][1]>intervals[i][0]){
                // overlapping interval found
                count++;
                if(intervals[i][1]<intervals[last][1]) last = i; 
            }
            else last = i;
        }
        
        return count;
    }
};