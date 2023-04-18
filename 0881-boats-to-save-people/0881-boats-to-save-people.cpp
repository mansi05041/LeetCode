class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // sort the array
        sort(people.begin(),people.end());
        int i =0;
        int j=people.size()-1;
        int boats =0;
        while(i<=j){
            boats++;
            if(people[i]+people[j]<=limit) i++;
            j--;
        }
        return boats;
    }
};