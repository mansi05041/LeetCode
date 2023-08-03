class Solution {
public:
    void helper(int idx,string digits,vector<string>& res,unordered_map<char,string>& mp,string str){
        // base case
        if(idx==digits.size()){
            res.push_back(str);
            return;
        }
        
        string letters = mp[digits[idx]];
        for(auto it:letters){
            helper(idx+1,digits,res,mp,str+it);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        
        unordered_map<char,string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        
        vector<string> res;
        helper(0,digits,res,mp,"");
        return res;
    }
};