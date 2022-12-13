class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_wealth=0;
        int curr_wealth=0;
        for(int i=0;i<accounts.size();i++){
            for(auto j: accounts[i]) curr_wealth+=j;
            max_wealth=max(max_wealth,curr_wealth);
            curr_wealth=0;
        }
        return(max_wealth);
    }
};