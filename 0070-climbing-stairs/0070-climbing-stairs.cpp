class Solution {
public:
    int climbStairs(int n) {
        // base case
        if(n==0 || n==1) return 1;
        int step1=1;
        int step2=1;
        int currStep;
        for(int i=2;i<=n;i++){
            // either it takes one step or two steps
            currStep = step1+step2;
            step1 = step2;
            step2 = currStep;
        }
        return step2;
    }
};