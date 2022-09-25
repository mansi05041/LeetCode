class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3) return{};
        sort(nums.begin(),nums.end()); // sort the array
        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-2;i++){
            if(i==0 || nums[i]!=nums[i-1]){
                int low=i+1;
                int high=nums.size()-1;
                while(low<high){
                if(nums[i]+nums[low]+nums[high]==0) {
                    ans.push_back({nums[i],nums[low],nums[high]});
                    while(low<high && nums[low]==nums[low+1]) low++;
                    while(low<high && nums[high]==nums[high-1]) high--;
                    low++,high--;
                }
                else if(nums[i]+nums[low]+nums[high]<0) low++;
                else high--;
                }

            }
        }
        return(ans);
    }
};