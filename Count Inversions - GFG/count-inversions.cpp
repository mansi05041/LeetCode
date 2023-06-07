//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[],long long left,long long right,long long mid){
        long long int inv =0;
        long long i = left;
        long long j = mid+1;
        long long k = 0;
        long long temp[right-left+1];
        
        while(i<=mid && j<=right){
            if(arr[i]>arr[j]){
                // we got the inversion
                inv+=(mid-i+1);
                temp[k]=arr[j];
                k++;
                j++;
            }
            else{
                temp[k]=arr[i];
                k++;
                i++;
            }
        }
        
        // copy the left out elements
        while(i<=mid){
            temp[k]=arr[i];
            k++;
            i++;
        }
        while(j<=right){
            temp[k]=arr[j];
            k++;
            j++;
        }
        
        // copy the temp values to original array
        for(int i=left,k=0;i<=right;i++,k++){
            arr[i]=temp[k];
        }
        
        return(inv);
    }
    long long int mergeSortModified(long long arr[],long long left, long long right){
        long long mid;
        long long int inv =0;
        if(right>left){
            mid=(left+right)/2;
            inv=mergeSortModified(arr,left,mid);
            inv+=mergeSortModified(arr,mid+1,right);
            inv+=merge(arr,left,right,mid);
        }
        return inv;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return mergeSortModified(arr,0,N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends