//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        
        // kadanes algorithm
        
        int ones = 0; 
        int count = 0; 
        int maxCount = 0; 
        
        for(int i=0;i<n;i++){
            if(a[i]==0){  
                // check if the count is not negative
                if(count>=0) count+=1; // include 0 to flip
                else count = 1; // reset count to 1
            }
            else{
                // increment the ones
                ones+=1;
                // decrement the count
                count-=1;
            }
            
            // update the max count of flip
            maxCount = max(maxCount,count);  
        }
        
        return ones+maxCount; 
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends