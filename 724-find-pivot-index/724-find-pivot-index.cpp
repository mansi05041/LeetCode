class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total=0;
        for(int i=0;i<nums.size();i++) total+=nums[i];
        int Lsum=0;
        int Rsum;
        for(int i=0;i<nums.size();i++){
            Rsum=total-Lsum-nums[i];
            if(Lsum==Rsum) return(i);
            Lsum+=nums[i];
        }
        return(-1);
    }
};