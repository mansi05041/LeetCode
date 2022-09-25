class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> map;
        for(int i=0;i<s.length();i++){
            map[s[i]]++;
        }
        for(int i=0;i<s.length();i++){
        for(auto x: map){
            if(x.second==1 && x.first==s[i]) return(i);
        }
            
        } 
        return(-1);
    }
};