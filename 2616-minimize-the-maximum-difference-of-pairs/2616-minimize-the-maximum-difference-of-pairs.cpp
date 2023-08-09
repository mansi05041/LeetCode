class Solution {
public:
    int countValidPairs(vector<int>&nums,int mid){
        int idx = 0;
        int count = 0;
        
        while(idx<nums.size()-1){
            if(nums[idx+1]-nums[idx]<=mid){  // 1-1 = 0<= 0
                // skip two indexes
                count++; // 1
                idx++; // 1
            }
            idx++; // 2
        }
        
        return count;
    }
    int minimizeMax(vector<int>& nums, int p) {
        // sort the array
        sort(nums.begin(),nums.end());   // 1 1 2 3 7 10
        int n = nums.size();
        int left = 0;
        int right = nums[n-1]-nums[0];  // search space [0,9]
        
        while(left<right){
            int mid = left + (right-left)/2; // 0
            
            if(countValidPairs(nums,mid)>=p) right = mid;  // 1>=2 [0,1]
            else left = mid+1; // left = 0 +1 = 1 [1]
        }
        return left; // 1
    }
};