class Solution {
public:
    void sortColors(vector<int>& nums) {
       int zero_ptr=0;
       int one_ptr=0;
       int two_ptr=nums.size()-1;
       while(one_ptr<=two_ptr){
           if(nums[one_ptr]==0){
               swap(nums[one_ptr],nums[zero_ptr]);
               one_ptr++;
               zero_ptr++;
           }
           else if(nums[one_ptr]==2){
               swap(nums[one_ptr],nums[two_ptr]);
               two_ptr--;
           }
           else{
               one_ptr++;
           }
       }
    }
};