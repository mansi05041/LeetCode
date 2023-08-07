# two pointer approach
maintain a pointer start that track the starting point of window
​
```
int minSubArrayLen(int target, vector<int>& nums) {
if(nums.size()==0) return 0;
int sum = 0;
int minSize = INT_MAX;
int start = 0;
for(int i=0;i<nums.size();i++){
sum+=nums[i];  // add into current sum
while(sum>=target){
minSize = min(minSize,i+1-start);  // maintain the minimum window
sum-=nums[start];  // decrease the window size
start++;
}
}
return minSize==INT_MAX ? 0 : minSize;
}
​
```
​
Time complexity : O(n)