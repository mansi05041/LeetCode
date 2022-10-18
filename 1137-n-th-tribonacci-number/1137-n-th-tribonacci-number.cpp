class Solution {
public:
    int tribonacci(int n) {
        if(n==1 || n==2) return(1);
        if(n==3) return(2);
        if(n>3){
            unsigned int first=0;
            unsigned int second=1;
            unsigned int third=1;
            unsigned int result;
            while(n-2>0){
                result=first+second+third;
                first=second;
                second=third;
                third=result;
                n-=1;
            }
            return(third);
        }
        return(0);
    }   
};