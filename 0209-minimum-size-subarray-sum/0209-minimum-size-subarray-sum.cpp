class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        if(nums.size()==0) return 0;
        
        int sum = 0;
        int minSize = INT_MAX;
        int start = 0;
       
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(sum>=target){
                minSize = min(minSize,i+1-start);
                sum-=nums[start];
                start++;
            }
        }
        return minSize==INT_MAX ? 0 : minSize;
    }
};