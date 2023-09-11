class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        unordered_map<int,vector<int>> mp;
        
        for(int i=0;i<groupSizes.size();i++){
            mp[groupSizes[i]].push_back(i);
            
            if(mp[groupSizes[i]].size()==groupSizes[i]){
                res.push_back(mp[groupSizes[i]]);
                mp[groupSizes[i]].clear();
            }
        }
        
        return res;
    }
};