class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans =0;
        while(a!=0|b!=0|c!=0){
            // least significant bit of c is 1
            if((c&1)==1){
                if((a&1)==0 && (b&1)==0) ans++;
            }
            // c has 0 as the least significant bit
            else ans+=(a&1)+(b&1);
            // shift the values to the right
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return ans;
    }
    
};