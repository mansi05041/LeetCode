class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0||(x%10==0 && x!=0)) return false;
        //if(x>=pow(-2,31) && x<=pow(2,31)-1) return false;
        int n=x;
        long long palindrome=0;
        while(n){
            palindrome=palindrome*10+n%10;
            n/=10;
        }
        //if(palindrome>=pow(-2,31) && palindrome<=pow(2,31)-1) return false;
        return (x==palindrome);
    }
};