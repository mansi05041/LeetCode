class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res;
        // sort the array
        sort(potions.begin(),potions.end());
        for(auto i: spells){
            int pos=potions.size();
            // applying binary search
            int left =0;
            int right =potions.size()-1;
            while(left<=right){
                int mid = left+(right-left)/2;
                if((long long)i*potions[mid]>=success){
                    right = mid-1;
                    pos = mid;
                }
                else left = mid+1;
            }
            res.push_back(potions.size()-pos);
        }
        return res;
    }
};