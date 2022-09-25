class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end()); // sort the array
        nums.erase(unique(nums.begin(), nums.end()), nums.end()); // remove the unique numbers
        reverse(nums.begin(),nums.end()); // reverse the array
        if(nums.size()<3) return(nums[0]); // maximum number
        return(nums[2]);
    }
};