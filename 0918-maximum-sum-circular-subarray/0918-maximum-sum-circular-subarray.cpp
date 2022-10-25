class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n= nums.size();
        int arr_sum=0;
        int max_str_sum=INT_MIN;
        int min_str_sum=INT_MAX;
        int temp_max_sum=0;
        int temp_min_sum=0;
        
        for(int x:nums){
            
            // calculating max_str_sum
            temp_max_sum+=x;
            max_str_sum=max(max_str_sum,temp_max_sum);
            temp_max_sum= temp_max_sum<0?0: temp_max_sum;
            
            // calculating arr_sum
            arr_sum+=x;
            
            // calculating min_str_sum
            temp_min_sum+=x;
            min_str_sum=min(min_str_sum,temp_min_sum);
            temp_min_sum=temp_min_sum>0?0:temp_min_sum;
            
        }
        
        // boundary case: all the elements are negative 
        if(arr_sum==min_str_sum) return(max_str_sum);
        
        return(max(max_str_sum,(arr_sum-min_str_sum)));
        
    }
};