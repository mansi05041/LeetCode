modified the above approach using cumulative sum, we get an extra space complexity : O(n)
​
```
int minSubArrayLen(int target, vector<int>& nums) {
if(nums.size()==0) return 0;
vector<int> sum(nums.size());
sum[0] = nums[0];
int minSize = INT_MAX;
// memorization: cumulative sum
for(int i=1;i<nums.size();i++){
sum[i] = sum[i-1]+nums[i];
}
for(int i=0;i<nums.size();i++){    // i is the start of window
for(int j=i;j<nums.size();j++){   // j is the end of window
int s = sum[j]-sum[i]+nums[i];    //  get the sum of the current window using cummulative sum
if(s>=target){
minSize = min(minSize,(j-i+1));
break;
}
}
}
return minSize==INT_MAX ? 0 : minSize;
}
```
​
Time Complexity: O(n<sup>2</sup>)
​
# binary search
we are applying binary search on the cumulative vector that used above.