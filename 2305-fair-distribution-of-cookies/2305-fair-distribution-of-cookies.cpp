class Solution {
public:
    void helper(vector<int>& cookies,int k,int idx,int& min_unfairness,vector<int>& distribution){
        // base case
        if(idx==cookies.size()){
            min_unfairness=min(min_unfairness,*max_element(distribution.begin(),distribution.end()));
            return;
        }
        
        if(min_unfairness<=*max_element(distribution.begin(),distribution.end())) return;
        
        for(int i=0;i<k;i++){
            distribution[i]+=cookies[idx];
            helper(cookies,k,idx+1,min_unfairness,distribution);
            // backtracking
            distribution[i]-=cookies[idx];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int min_unfairness = INT_MAX;
        vector<int> distribution(k);
        helper(cookies,k,0,min_unfairness,distribution);
        return min_unfairness;
    }
};