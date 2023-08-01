class Solution {
public:
    void helper(int idx,int n,int k,vector<int> temp,vector<vector<int>>& ans){
        // base case
        if(k==0) {
            ans.push_back(temp);
            return;
        }
        
        for(int i=idx;i<=n;i++){
            temp.push_back(i);
            helper(i+1,n,k-1,temp,ans);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        // backtracking
        vector<vector<int>> ans;
        helper(1,n,k,{},ans);
        return ans;
    }
};