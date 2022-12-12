class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        // best case : O(1)
        
        // if they are already 
        if(s1==s2) return true;
        
        // if they are unequal size 
        if(s1.size()!=s2.size()) return false;
        
        // worst case : O(n)
        
        // find the start and end pos to swap
        int st,end;
        
        // iterate for st
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]) {
                st=i;
                break;
            }
        }
        
        // iterate for end
        for(int i=s1.size()-1;i>-1;i--){
            if(s1[i]!=s2[i]){
                end=i;
                break;
            }
        }
        
        // swap the positions in string s1 (performing one time only)
        swap(s1[st],s1[end]);
            
        // return the boolean value
        return(s1==s2);
        
    }
};