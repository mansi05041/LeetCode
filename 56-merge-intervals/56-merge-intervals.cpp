class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        // edge case
        if(intervals.size()==0) return(result);
        if(intervals.size()==1) return(intervals);
        // sort the intervals
        sort(intervals.begin(),intervals.end());
        
        // use the temporary vector for comparision
        vector<int> temp=intervals[0];
        
        // iterating in the loop for merging
        for(auto it:intervals){
            if(it[0]<=temp[1]) temp[1]=max(temp[1],it[1]);
            else{
                result.push_back(temp);
                temp=it;
            }
        }
        
        // append the last interval left
        result.push_back(temp);
        return(result);
    }
};