class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersect;
        if(nums1.size()<=nums2.size()){
            swap(nums1,nums2);
        }
        map<int,int> st;
        for(int i=0;i<nums1.size();i++){
            st[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            if(st.find(nums2[i])!=st.end()){
                intersect.push_back(nums2[i]);
                st[nums2[i]]--;
                if(st[nums2[i]]==0){
                    st.erase(nums2[i]);
                }
            }
        }
        return(intersect);
    }
};