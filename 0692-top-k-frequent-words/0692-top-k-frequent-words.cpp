class Solution {
public:
    
    struct ComparePairs{
        bool operator()(const pair<int,string>&p1, const pair<int,string>&p2){
            if(p1.first!=p2.first) return p1.first<p2.first; // order by frequency in descending order
            return p1.second>p2.second; // order by string in lexicographic order
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        // use hash map to store the frequency of words
        unordered_map<string,int> mp;
        for(auto s: words){
            mp[s]++;
        }
        
        // use priority queue to store the highest frequency with lexicographic order
        priority_queue<pair<int,string>, vector<pair<int,string>>, ComparePairs> pq;
        for(auto it: mp){
            pq.push({it.second,it.first});
        }
        
        // preparing answer
        vector<string> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};