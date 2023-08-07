class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroCount = 0;
        int WindowSize = 0;
        int start = 0;
        
        for(int i=0;i<nums.size();i++){
            // update the Zero count
            zeroCount+= (nums[i]==0);
            
            // shrink the window size until the zeroCount is less than or equal to 1
            while(zeroCount>1){
                zeroCount-=(nums[start]==0);
                start++;
            }
            
            // update the window size
            WindowSize= max(WindowSize,i-start);
        }
        
        return WindowSize;
    }
};