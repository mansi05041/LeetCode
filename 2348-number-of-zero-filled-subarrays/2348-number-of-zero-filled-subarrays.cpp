class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count =0;
        int lastInvalidEle =-1; // track the last index which is not zero
        int lastMinIdx = -1; // track the last min index where 0 is found
        int lastMaxIdx =-1; // track the last max index where 0 is found
        for(int i=0;i<nums.size();i++){
            // only if the value is equal to 0
            if(nums[i]==0){
                lastMinIdx = (nums[i]==0) ? i : lastMinIdx;
                lastMaxIdx = (nums[i]==0) ? i : lastMaxIdx;
                
                // update the count
                count+=max(0,min(lastMinIdx,lastMaxIdx)-lastInvalidEle);
            }
            else{
                // update the lastInavlidEle and other parameters
                lastInvalidEle = i;
                lastMinIdx =-1;
                lastMaxIdx =-1;
            }
        }
        return count;
        
    }
};