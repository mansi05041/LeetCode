class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        set<char> ch;
        int max=0;
        while(r<s.length()){
            auto itr =ch.find(s[r]);
            if(itr==ch.end()){
                if(r-l+1>max) max=r-l+1;
                ch.insert(s[r]);
                r++;
            }
            else{
                ch.erase(s[l]);
                l++;
            }
        }
        return(max);
    }
};