class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            int t=0;
            int n=nums[i];
            while(n>0){
                t+=1;
                n/=10;
            }
            if(t%2==0) count+=1;
        }
        return(count);
        
    }
};