class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            // target is found 
            if(nums[mid]==target) return mid;
            
            // if left half sorted
            if(nums[low]<=nums[mid]){
                // target lies in the range of [low-mid]
                if(nums[low]<=target && target<nums[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            // the right half sorted
            else{
                // if the target lies in [mid-high]
                if(nums[mid]<target && target<=nums[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        
        return -1;
    }
};