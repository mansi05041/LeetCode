class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        if(n<=1) return(0);
        int max_left=height[0];
        int max_right=height[n-1];
        int left=0;
        int right=n-1;
        int trap_water=0;
        
        while(left<=right){
            if(max_left<=height[left]) max_left=height[left];
            if(max_right<=height[right]) max_right=height[right];
            
            if(max_left<max_right) {
                trap_water=max(trap_water,max_left*(right-left));
                left++;
            }
            else{
                   trap_water=max(trap_water,max_right*(right-left));
                   right--;
            }
        }
       return(trap_water); 
    }
};