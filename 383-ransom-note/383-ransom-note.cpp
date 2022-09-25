class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>m;
        for(int i=0;i<magazine.size();i++){
            m[magazine[i]]++;
        }
        int count=0;
        for(int j=0;j<ransomNote.size();j++){
            if(m.find(ransomNote[j])!=m.end() && m[ransomNote[j]]>0) {
                m[ransomNote[j]]-=1;
                count++;
            }
        }
        if(count==ransomNote.size()) return true;
        return false;
    }
};