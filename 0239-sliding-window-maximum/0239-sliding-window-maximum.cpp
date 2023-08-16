class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;
        vector<int> res;
        
        // first k elements
        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[i]>=nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }
        
        res.push_back(nums[dq.front()]);
        
        // next elements
        for(int i=k;i<nums.size();i++){
            // shrink the sliding window
            if(dq.front()==i-k) dq.pop_front();
            
            while(!dq.empty() && nums[i]>=nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
            res.push_back(nums[dq.front()]);
        }
        
        return res;
    }
};