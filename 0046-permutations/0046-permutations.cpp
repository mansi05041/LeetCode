class Solution {
public:
    void helper(vector<int>& nums,vector<vector<int>>& ans,vector<int>& temp){
        // base case
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        
        for(auto num:nums){
            if(find(temp.begin(),temp.end(),num)==temp.end()){
                temp.push_back(num);
                helper(nums,ans,temp);
                temp.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums,ans,temp);
        return ans;
    }
};