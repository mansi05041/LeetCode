class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // use binary search 
        int n1=nums1.size();
        int n2=nums2.size();
        
        // apply operation on nums1 , it should be less in size
        if(n1>n2) return(findMedianSortedArrays(nums2,nums1));
        
        int total = n1+n2;
        int half=(total+1)/2;
        // binary search in nums1
        int low=0;
        int high=n1;
        while(low<=high){
            int i=low+(high-low)/2;  // for nums1
            int j=half-i;   // for nums2
            int left1= i==0? INT_MIN: nums1[i-1];
            int right1= i==n1? INT_MAX: nums1[i];
            int left2= j==0? INT_MIN: nums2[j-1];
            int right2= j==n2? INT_MAX: nums2[j];
            
            if(left1>right2 && left2<=right1) high=i-1;
            else if(left1<=right2 && left2>right1) low=i+1;
            else{
                if(total%2==0) return((max(left1,left2)+min(right1,right2))/2.0);
                else return(max(left1,left2));
            }
        }
        return 0.0;
    }
};