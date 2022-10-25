class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      
        int n=nums.size();
        
        // change all the -ves , 0s and more than n to n+1
        for(auto &x: nums){
            if(x<=0 || x>n) x=n+1;
        }
        
        // mapped the value using indexes
        for(auto &x: nums){
            if(abs(x)<=n && nums[abs(x)-1]>0) nums[abs(x)-1]*=(-1);
        }
        
        // return the smallest intger
        for(int i=0;i<n;i++){
            if(nums[i]>=0) return(i+1);
        }
        
        return(n+1);
    }
};