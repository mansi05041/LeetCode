class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // used priority queue to find the largest element
        priority_queue<int> pq;
        for(auto i: nums){
            pq.push(i);
        }
        int n = k;
        while(n!=1){
            pq.pop();
            n--;
        }
        return(pq.top());
    }
};