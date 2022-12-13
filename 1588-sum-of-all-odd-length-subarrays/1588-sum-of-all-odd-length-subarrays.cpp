class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int left = i;
            int right = n-i-1;
            // odd subarray add
            sum+=arr[i]*((left/2 +1)*(right/2 +1));
            // even subarray add
            sum+=arr[i]*((left+1)/2)*((right+1)/2);
        }
        return sum;
    }
};