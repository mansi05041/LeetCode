class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=prices[0]; // supposing that it is minimum in array
        int max=0; // in case no profit found
        for(int i=1;i<prices.size();i++){
            if(prices[i]<min) min=prices[i];
            else if(prices[i]-min>max) max=prices[i]-min;
        }
        return(max);
    }
};