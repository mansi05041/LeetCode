class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> Prefix;
        int count=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i]; 
            if(sum==k) count+=1;
            if(Prefix.find(sum-k)!=Prefix.end()){
                count+=Prefix[sum-k];
            }
            Prefix[sum]++;
        }
        return count;
    }
};