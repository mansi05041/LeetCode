class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        // used priority queue to store the scores
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<score.size();i++){
            pq.push({score[i],i});
        }
        
        // map to store the placement
        map<string,pair<int,int>> mp;
        int k=1;
        while(!pq.empty()){
            if(k==1){
                mp["Gold Medal"]=pq.top();
            }
            else if(k==2){
                mp["Silver Medal"]=pq.top();
            }
            else if(k==3){
                mp["Bronze Medal"]=pq.top();
            }
            else{
                string st = to_string(k);
                mp[st]=pq.top();
            }
            pq.pop();
            k++;
        }
        
        // prepare answer
        vector<string> reward(score.size());
        for(auto it: mp){
            int pos = it.second.second;
            reward[pos]=it.first;
        }
        
        return reward;
    }
};