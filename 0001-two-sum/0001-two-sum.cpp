class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // key: target-currentEle, val:index
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            // check if the currentEle is present in the map or not
            if(mp.find(target-nums[i])!=mp.end()){
                // present 
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
                break;
            }
            else{
                // not present
                mp[nums[i]]=i;
            }
        }
        return ans;
    }
};