
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> freq;
        for(int i=0;i<s.length();i++){
            freq[s[i]]++;
            freq[t[i]]--;
        }
        for(auto x:freq){
            if(x.second) return false;
        }
        return true;
    }
};
