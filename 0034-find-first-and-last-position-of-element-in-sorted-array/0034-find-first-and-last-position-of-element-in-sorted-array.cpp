class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int low, int high, bool left){
        int i=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                i=mid;
                if(left) high=mid-1;
                else low=mid+1;
            }
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return(i);
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=binarySearch(nums,target,0,nums.size()-1,true);
        int right=binarySearch(nums,target,0,nums.size()-1,false);
        return{left,right};
    }
};