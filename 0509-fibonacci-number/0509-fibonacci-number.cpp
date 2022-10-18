class Solution {
public:
    int fib(int n) {
        if(n==1) return(1);
        if(n==2) return(1);
        if(n>2){
            int first=0;
            int second=1;
            int third;
            while(n-1>0){
                third=first+second;
                first=second;
                second=third;
                n-=1;
            }
            return(second);
        }
       return(0);
    }   
};