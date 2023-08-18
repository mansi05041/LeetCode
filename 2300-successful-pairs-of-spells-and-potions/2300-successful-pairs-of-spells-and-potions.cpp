class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res;
        
        // sort the potions
        sort(potions.begin(),potions.end());
        
        for(auto spell: spells){
            int pos = potions.size();
            int low = 0;
            int high = potions.size()-1;
            
            while(low<=high){
                int mid = low + (high-low)/2;
                
                if((long long)spell*potions[mid]<success) low = mid+1;
                else{
                    pos = mid;
                    high = mid-1;
                }
            }
            
            res.push_back(potions.size()-pos);
        }
        
        return res;
    }
};