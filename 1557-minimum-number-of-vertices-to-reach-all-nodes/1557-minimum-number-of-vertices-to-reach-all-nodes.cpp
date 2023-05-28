class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // indegree = 0 will be considered the answer
        
        map<int,int> mp; // it will store the indegree
        for(auto it: edges){
            if(mp.find(it[0])==mp.end()) mp[it[0]] = 0; 
            mp[it[1]]++;
        }
        vector<int> res;
        for(auto it: mp){
            if(it.second==0) res.push_back(it.first);
        }
        return res;
    }
};