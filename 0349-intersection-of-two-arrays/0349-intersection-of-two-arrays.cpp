class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        /*set<int> s1,s2;
        // unique values 
        for(auto it:nums1){
            s1.insert(it); // 1 2 
        }
        for(auto it:nums2){
            s2.insert(it); // 2
        }*/
        
        set<int> s1(nums1.begin(),nums1.end());
        set<int> s2(nums2.begin(),nums2.end());
        
        /*
        // value-freq map
        unordered_map<int,int> mp;
        for(auto it: s1){
            mp[it]++;
        }
        for(auto it: s2){
            mp[it]++;
        }
        
        vector<int> ans;
        for(auto it:mp){
            if(it.second>1) ans.push_back(it.first);
        }*/
        vector<int> result;
        set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),back_inserter(result));
        
        return result;
    }
};