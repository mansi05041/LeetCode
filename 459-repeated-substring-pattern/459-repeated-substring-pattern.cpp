class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.length(); 
        if(n==0) return true;
        
        for(int len=1;len<=n/2;len++){
            if(n%len!=0) continue;
            string pattern = s.substr(0,len);
            int i=len;
            int j=i+len-1;
            while(j<n){
                string check=s.substr(i,len);
                if(check!=pattern) break;
                i+=len;
                j+=len;
            }
           if(i==n) return true;
        }
        return false;
    }
};