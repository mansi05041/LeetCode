class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> sum;
        int count=0;
        int max=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) {
                count+=1;
                if(max<count) max=count;}
            else{
                count=0;
            }
            
        }
        return(max);
        
    }
};