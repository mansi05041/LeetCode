class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count =0;
        int lastInvalidEle = -1; // track the last invalid element in array
        int lastMinIdx = -1; // track the index of min value in the last of subarray
        int lastMaxIdx = -1; // track the index of max value in  the last of subarray
        for(int i=0;i<nums.size();i++){
            // only the elements that fall in range
            if(nums[i]>=minK && nums[i]<=maxK){
                // update the lastMinIdx and lastMaxIdx
                lastMinIdx = (nums[i]==minK)? i : lastMinIdx;
                lastMaxIdx = (nums[i]==maxK)? i : lastMaxIdx;
                
                // update the count
                count+=max(0,min(lastMinIdx,lastMaxIdx)-lastInvalidEle);
            }
            else{
                // update the lastInvalidEle and set the lastMinIdx and lastMaxIdx as -1
                lastInvalidEle = i;
                lastMinIdx =-1;
                lastMaxIdx = -1;
            }
        }
        return count;
    }
};