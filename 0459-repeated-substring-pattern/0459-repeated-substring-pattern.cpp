class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.size()<1) return true;
    
        for(int i=1;i<=s.size()/2;i++){
            string str = s.substr(0,i);
            
            if(s.size()%str.size()!=0) continue;
            
            int idx = str.size();
            while(idx<s.size() && str==s.substr(idx,str.size())){
                idx+=str.size();
            }
            
            if(idx==s.size()) return true;
        }
        
        return false;
    }
};