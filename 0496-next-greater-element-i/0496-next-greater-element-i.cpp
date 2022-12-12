class Solution {
public:
    vector<int> Next(vector<int>& nums){
        stack<int> st;
        vector<int> NS(nums.size());
        
        for(int i=nums.size()-1;i>-1;i--){
            
            // remove the values till we get greater value
            while(st.empty()==false && nums[i]>nums[st.top()]) st.pop();
            
            // if stack is empty, there is no greater element on the right
            if(st.empty()) NS[i]=-1;
            
            else NS[i]=nums[st.top()];
            
            // push the current index of array into the stack
            st.push(i);
            
        }
        
        return NS;
    }
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        // get the next Greater Element for all values
        vector<int> NS=Next(nums2);
        
        // we store the values in hashmap , key->nums2[i] and value->NS[i];
        unordered_map<int,int> mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]=NS[i];
        }
        
        // find the Next greater element for nums1
        vector<int> ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            ans[i]=mp[nums1[i]];
        }
        
        // return the resultant array
        return ans;
    }
};