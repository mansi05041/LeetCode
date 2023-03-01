class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // sort the vector
        sort(nums.begin(),nums.end());
        
        // use hash map to save frequency
        unordered_map<int,int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        
        // use the priority queue to find the most frequent element use
        priority_queue<pair<int,int>> pq;
        for(auto it: mp){
            pq.push({it.second,it.first});
        }
        
        // store the values in resultant vector
        vector<int> result;
        int n=k;
        while(n){
            n--;
            int r = pq.top().second;
            result.push_back(r);
            pq.pop();
        }
        
        return result;
    }
};