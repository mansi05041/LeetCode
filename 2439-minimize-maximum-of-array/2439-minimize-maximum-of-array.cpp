class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        // prefix sum is used in the continous array
        // the average of the values that seen in continous will be updated as result
        long long prefixSum = nums[0];
        long long result = nums[0];
        for(int i=1;i<nums.size();i++){
            prefixSum+=nums[i];
            result = max(result,(prefixSum+i)/(i+1));
        }
        return (int)result;
    }
};