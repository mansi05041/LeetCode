# brute force approach
try out all the possible ways
```
int minSubArrayLen(int target, vector<int>& nums) {
int minSize = INT_MAX;
for(int i=0;i<nums.size();i++){   // start of window
for(int j=i;j<nums.size();j++){  // end of window
int sum = 0;
for(int k=i;k<=j;k++){  // getting the elements of current window
sum+=nums[k];
}
if(sum>=target){
minSize = min(minSize,(j-i+1));
break;
}
}
}
return minSize==INT_MAX ? 0 : minSize;
}
```
Time complexity: O(n<sup>3</sup>)
​
# better brute force approach
modified the above approach using cumulative sum, we get an extra space complexity : O(n)