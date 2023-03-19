class Solution {
public:
    void Merge(vector<int> &arr,int start,int mid,int end,vector<int> &temp){
        int start1 = start;
        int start2 = mid+1;
        int n1 = mid-start+1;
        int n2 = end - mid;
        
        // copy the elements of both halves into a temp array
        for(int i=0;i<n1;i++){
            temp[start1+i]=arr[start1+i];
        }
        for(int i=0;i<n2;i++){
            temp[start2+i]=arr[start2+i];
        }
        
        
        // Merge the sub-arrays in temp back into the orginal 
        int i=0, j=0, k=start;
        while(i<n1 && j<n2){
            if(temp[start1+i]<=temp[start2+j]){
                arr[k]=temp[start1+i];
                i++;
            }
            else{
                arr[k]=temp[start2+j];
                j++;
            }
            k++;
        }
        
        // copy the remaining elements
        while(i<n1){
            arr[k]=temp[start1+i];
            i++;
            k++;
        }
        while(j<n2){
            arr[k]=temp[start2+j];
            j++;
            k++;
        }
    }
    
    void MergeSort(vector<int> &arr,int start,int end,vector<int> &temp){
        if(start<end){
            int middle = start + (end-start)/2;
            // recursively call MergeSort for left part
            MergeSort(arr,start,middle,temp);
            // recursively call MergeSort for right part
            MergeSort(arr,middle+1,end,temp);
            // merge the left and right
            Merge(arr,start,middle,end,temp);
        }
        return;
    }
    
    vector<int> sortArray(vector<int>& nums) {
        // merge sort O(nlogn)
        int n = nums.size();
        vector<int> temp(n);
        MergeSort(nums,0,n-1,temp);
        return nums;
    }
};