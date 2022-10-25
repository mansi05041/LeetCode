class Solution {
public:
    int issubstr(string s1,string s2){
        if(s2.find(s1)!=string::npos){
            return(s2.find(s1));
        }
        return(-1);
    }
    int strStr(string haystack, string needle) {
        return(issubstr(needle,haystack));
    }
};