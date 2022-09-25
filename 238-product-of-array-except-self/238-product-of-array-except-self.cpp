class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pro;
        int left_pro=1;
        for(int i=0;i<nums.size();i++){
            left_pro*=nums[i];
            pro.push_back(left_pro);
        }
        int right_pro=1;
        for(int i=nums.size()-1;i>-1;i--){
            // boundary conditions
           
            if(i==nums.size()-1){
                pro[i]=pro[i-1];
            }
            else if(i==0){
                pro[i]=right_pro;
            }
            else{
                pro[i]=pro[i-1]*right_pro;
            }
            right_pro*=nums[i];
        }
        return(pro);
    }
};