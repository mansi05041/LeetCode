class Solution {
public:
    int bestClosingTime(string customers) {
        int minPenalty = 0;
        int closingTime = 0;
        
        // getting the penalty at 0th hour
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='Y') minPenalty++;
        }
        
        int penalty = minPenalty;
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='Y') penalty--;
            else penalty++;
            
            if(minPenalty>penalty){
                penalty = minPenalty;
                closingTime = i+1;
            }
        }
        
        return closingTime;
    }
};