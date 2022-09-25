class Solution {
public:
    
    bool binary_search(vector<int>& arr,int l,int r,int ele){
        if(l<=r){
        int mid = l + (r - l) / 2;
        if(arr[mid]==ele) return true;
        else if(arr[mid]>ele) return(binary_search(arr,l,mid-1,ele));
        else return(binary_search(arr,mid+1,r,ele));
        }
       return false;
    }
    
    bool checkIfExist(vector<int>& arr) {
      sort(arr.begin(),arr.end());
      for(int i=0;i<arr.size();i++){
          if(arr[i]==0) i++;
          if(binary_search(arr,0,arr.size()-1,arr[i]*2)) return true;
      }
     return false;
    }
};