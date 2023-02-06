class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int left =0;
        int currFruits;
        int maxFruits =INT_MIN;
        for(int right=0;right<fruits.size();right++){
            // store the current fruit in map
            mp[fruits[right]]++;
            
            // if the size of map is greater than 2 
            while(left<=right && mp.size()>2){
                
                // remove the previous fruit from map
                mp[fruits[left]]--;
                // if the freq becomes zero then remove it from map
                if(mp[fruits[left]]==0) mp.erase(fruits[left]);
                left++;
            }
            // update the max fruits we get so far
            currFruits=(right-left+1);
            maxFruits = max(maxFruits,currFruits);
        }
        return maxFruits;
    }
};