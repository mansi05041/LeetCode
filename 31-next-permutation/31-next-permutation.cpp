class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i,j;
        
        // find the mountain element from right side
        for(i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]) break;
        }
        
        // check if the permutation itself is the greatest 
        if(i<0) sort(nums.begin(),nums.end()); // sort the array : O(nlogn)
        
        else{
            
        // check the just largest element from mountain element starting with right side
        for(j=n-1;j>i;j--){
            if(nums[j]>nums[i]) break;
        }
            
         // swap the montain element and the just larger element
         swap(nums[i],nums[j]);
            
         // reverse the elements after the mountain element to end of vector
         reverse(nums.begin()+i+1,nums.end());   
        }
     
    }
};