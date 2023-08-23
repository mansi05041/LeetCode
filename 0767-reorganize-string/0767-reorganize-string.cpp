class Solution {
public:
    string reorganizeString(string s) {
        
        // map to store the frequency
        unordered_map<char,int> mp;
        for(auto ch:s){
            mp[ch]++;
        }
        
        // max heap to store the maxium frequency character
        priority_queue<pair<int,char>> pq;
        
        for(auto it: mp){
            pq.push({it.second,it.first});
        }
        
        string result;
        while(!pq.empty()){
            
            // remove the first character from max heap
            auto ch = pq.top().second;
            auto freq = pq.top().first;
            pq.pop();
            
            // if the result is empty or the previous charcter doesn't match with the current character
            if(result.empty() || ch!=result.back()){
                result+=ch;
                if(--freq>0) pq.push({freq,ch});
            }
            // try out the second character then
            else{
                if(pq.empty()) return "";  // if the priority queue doesn't have any characters, it is not possible to form then return empty string
                auto nch = pq.top().second;
                auto nfreq = pq.top().first;
                pq.pop();
                result+=nch;
                if(--nfreq>0) pq.push({nfreq,nch});
                pq.push({freq,ch}); // now push the first character
            }
        }
        
        return result;
    }
};