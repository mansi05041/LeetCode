class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> mp;
        for(auto i:s){
            mp[i]++;
        }
        for(auto it: mp){
            pq.push({it.second,it.first});
        }
        string res="";
        while(!pq.empty()){
            int freq=pq.top().first;
            while(freq--){
                res+=pq.top().second;
            }
            pq.pop();
        }
        return res;
    }
};