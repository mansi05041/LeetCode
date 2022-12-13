class Solution {
public:
    string toLowerCase(string s) {
        string ans="";
        for(auto i: s){
            if(isupper(i)) ans+=tolower(i);
            else ans+=i;
        }
        return ans;
    }
};