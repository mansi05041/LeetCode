class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        if(s.size()!=goal.size()) return false;
        
        // if s and goal are already equal
        if(s==goal){
            unordered_map<char,int> mp;
            for(auto it:s) mp[it]++;
            
            for(auto it:mp) if(it.second>1) return true;
            
            return false;
        }
        
        vector<int> idx;
        for(int i=0;i<s.size();i++){
            if(s[i]!=goal[i]) idx.push_back(i);
        }
        
        if(idx.size()!=2) return false;
        
        // perform swapping
        swap(s[idx[0]],s[idx[1]]);
        if(s==goal) return true;
        return false;
    }
};