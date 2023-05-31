class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        // result vector
        vector<vector<int>> result;
        
        // base case
        if(nums.size()<=1) return{nums};
        
        for(int i=0;i<nums.size();i++){
            vector<int> v(nums.begin(),nums.end());
            // remove the character at ith position
            v.erase(v.begin()+i);
            // Recursively call the function
            auto perms = permute(v);
            // append the removed digit
            for(auto it: perms){
                it.push_back(nums[i]);
                result.push_back(it);
            }
        }
        return result;
    }
};