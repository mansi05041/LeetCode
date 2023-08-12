class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        // sort the ages
        sort(ages.begin(), ages.end());
        
        int req = 0;
        
        for (int i = 0; i < ages.size(); i++) {
            int x = ages[i];
            int y = x/2 + 7;
            
            if(y>=x) continue;
            
            int idx1 = upper_bound(ages.begin(), ages.end(), y) - ages.begin();
            int idx2 = upper_bound(ages.begin(), ages.end(), x) - ages.begin();
            
            if(idx1<i) req+= (i-idx1);  // left of i
            if(idx2>i) req+= (idx2-i-1);  // right of i
        
        }
        
        return req;
    }
};
