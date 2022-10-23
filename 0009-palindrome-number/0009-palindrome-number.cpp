class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0||(x%10==0 && x!=0)) return false;
        
        int n=x;
        long long palindrome=0;
        while(n){
            palindrome=palindrome*10+n%10;
            n/=10;
        }
        
        return (x==palindrome);
    }
};