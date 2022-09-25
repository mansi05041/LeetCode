class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int rightmax=-1;
        int max_;
        for(int i=arr.size()-1;i>-1;i--){
            max_=max(arr[i],rightmax);
            arr[i]=rightmax;
            rightmax=max_;
        }
        return(arr);
    }
};