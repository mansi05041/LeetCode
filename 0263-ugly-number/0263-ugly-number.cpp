class Solution {
public:
    int divide(int n,int d){
        if(n>1){
            return n/d;
        }
        return 1;
    }
    
    bool isUgly(int n) {
        if(n<=0) return false;
        
        // if it is divisible by 2
        if(n%2==0){
            // keep dividing it by 2
            while(n%2==0)  n=divide(n,2);
        }
         // if it is divisible by 3
        if(n%3==0){
            // keep dividing it by 3
            while(n%3==0)  n=divide(n,3);
        }
         // if it is divisible by 5
        if(n%5==0){
            // keep dividing it by 5
            while(n%5==0)  n=divide(n,5);
        }
        return (n==1);
    }
};