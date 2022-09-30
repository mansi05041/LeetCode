class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int max_left=height[0];
        int max_right=height[n-1];
        int left=1;
        int right=n-2;
        int trap_water=0;
        while(left<=right){
            if(max_left<max_right){
                if(max_left<=height[left]) max_left=height[left];
                else trap_water+=max_left-height[left];
                left++;
            }
            else{
                if(max_right<=height[right]) max_right=height[right];
                else trap_water+=max_right-height[right];
                right--;
            }
        }
        
        return(trap_water);
    }
};