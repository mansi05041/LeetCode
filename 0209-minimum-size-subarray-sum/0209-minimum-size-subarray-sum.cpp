class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        if(nums.size()==0) return 0;
        
        vector<int> sum(nums.size()+1);
        sum[0] = nums[0];
        int minSize = INT_MAX;
        
        // calculate of sum of first n elements
        for(int i=1;i<=nums.size();i++){
            sum[i] = sum[i-1]+nums[i-1];
        }
        
        for(int i=1;i<=nums.size();i++){
            int findEle = target + sum[i-1];
            auto bound = lower_bound(sum.begin(),sum.end(),findEle);
            if(bound!=sum.end()){
                minSize = min(minSize,static_cast<int>(bound-(sum.begin()+i-1)));
            }
        }
        
        return minSize==INT_MAX ? 0 : minSize;
    }
};