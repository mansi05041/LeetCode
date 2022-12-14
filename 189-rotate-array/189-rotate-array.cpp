class Solution {
public:
    void reverse_array(vector<int>& nums,int left,int right){
        while(left<right){
            swap(nums[left],nums[right]);
            left++;
            right--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse_array(nums,0,n-1);
        reverse_array(nums,0,k-1);
        reverse_array(nums,k,n-1);
    }
};