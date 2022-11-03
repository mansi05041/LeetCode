class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // use hash map to store sum as key and value is the index where it occurs first time
        unordered_map<int,int> mp;
        
        int result=0;
        int sum=0;
        
        for(int i=0;i<nums.size();++i){
            sum+=(nums[i]==0)? -1:1;
            
            // case 1: sum=0 
            if(sum==0){
                result=max(result,i+1);
            }
            
            // case 2: sum is present in hash map
            else if(mp.find(sum)!=mp.end()){
                result=max(result,i-mp[sum]);
            }
            
            // case 3: encountered the sum first time
            else{
                mp[sum]=i;
            }
            
        }
        
        return result;
    }
};