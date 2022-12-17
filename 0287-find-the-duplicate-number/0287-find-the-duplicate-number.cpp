class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int pos;
        for(int i=0;i<nums.size();i++){
            pos=abs(nums[i]);
            if(nums[pos]<0) return(pos);
            nums[pos]*=(-1);
        }
        
        return(nums.size());
    }
};