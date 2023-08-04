class Solution {
public:
    bool Memorization(set<string> st,vector<int>& dp,int idx,string s){
        // base case : we reached the destination
        if(idx==s.size()) return true;
        
        // if the problem is already solved
        if(dp[idx]!=-1) return dp[idx];
        
        for(int i=idx;i<s.size();i++){
            if(st.find(s.substr(idx,i-idx+1))!=st.end()){
                // substring found in set
                if(Memorization(st,dp,i+1,s)){
                    dp[idx] = 1;
                    return true;
                }
            }
        }
        
        dp[idx] = 0;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto it: wordDict) st.insert(it);
        
        vector<int> dp(s.size(),-1);
        
        return Memorization(st,dp,0,s);
    }
};