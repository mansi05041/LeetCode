class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int left=0;
        int right=arr.size()-1;
        while(left<arr.size()-1 && arr[left]<arr[left+1]) left++;
        while(right>0 && arr[right-1]>arr[right]) right--;
        if(left>0 && left==right && right<arr.size()-1) return true;
        return false;
    }
};