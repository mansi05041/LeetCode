class Solution {
public:
    int expandAroundCenter(string s,int left, int right){
        int L=left;
        int R=right;
        while(L>=0 && R<s.length() && s[L]==s[R]){
            L--;
            R++;
        }
        return R-L-1;
    }
    
    string longestPalindrome(string s) {
        // base case : if there is empty string
        if(s.size()<1) return "";
        int start=0;
        int ans=0;        
        for(int i=0;i<s.size();i++){
           int len1 = expandAroundCenter(s,i,i);
           int len2 = expandAroundCenter(s,i,i+1);
           int len = max(len1,len2);
           if(len>ans){
               start=i-(len-1)/2;
               ans=len;
           }
        }
        return(s.substr(start,ans));
    }
};