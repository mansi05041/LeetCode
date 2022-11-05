class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seq;
        // storing values in the set
        for(int i=0;i<nums.size();i++) seq.insert(nums[i]);
        int len;
        int maxlen=0;
        // iterate through set
        for(auto x:seq){
            // check if there is no element smaller than current element in set
            if(!seq.count(x-1)){
                len=1; // intially length is 1
                int current=x;
                while(seq.count(current+1)){
                    len+=1;
                    current+=1;
                }
                maxlen=max(maxlen,len);
            }
        }
        return(maxlen);
    }
};