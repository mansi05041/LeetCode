class Solution {
public:
    int gcd(int a,int b){
        int res = min(a,b);
        while(res){
            if(a%res==0 && b%res==0) return res;
            res--;
        }
        
        return res;
    }
    string gcdOfStrings(string str1, string str2) {
        return (str1+str2==str2+str1)? str1.substr(0,gcd(str1.size(),str2.size())) : "";
    }
};