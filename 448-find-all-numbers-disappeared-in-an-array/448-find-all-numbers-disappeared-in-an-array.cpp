class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int idx;
        for(int i=0;i<nums.size();i++){
            idx=abs(nums[i])-1;
            if(nums[idx]>0) nums[idx]*=-1;
        }
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) res.push_back(i+1);
        }
        return(res);
    }
};