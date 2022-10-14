class Solution {
public:
    vector<int> reverse(vector<int>& arr,int low,int high){
        while(low<=high){
            swap(arr[low],arr[high]);
            low++;
            high--;
        }
        return(arr);
    }
    
    vector<int> pancakeSort(vector<int>& arr) {
        // O(n^2) approach
        vector<int> result;
        for(int i=arr.size()-1;i>0;i--){
            int maxIdx=i;
            for(int j=0;j<=i;j++){
                maxIdx= (arr[maxIdx]<arr[j]) ? j:maxIdx;
            }
            if(maxIdx!=i){
                arr=reverse(arr,0,maxIdx);
                result.push_back(maxIdx+1);
                arr=reverse(arr,0,i);
                result.push_back(i+1);
            }
        }
        return(result);
    }
};