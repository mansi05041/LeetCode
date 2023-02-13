class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // map the value and frequency
        unordered_map<char,int> mp;
        for(auto i: tasks){
            mp[i]++;
        }
        // store the max in priority queue
        priority_queue<pair<int,char>> pq;
        for(auto it: mp){
            pq.push({it.second,it.first});
        }
        
        // find the total time until the priority queue gets empty
        int totalTime=0;
        int cycle=n+1;
        while(!pq.empty()){
            vector<pair<int,char>> V;
            int time=0;
            for(int i=0;i<=n;i++){
                if(!pq.empty()){
                    V.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
                
            for(auto task:V){
                    if(--task.first){
                        pq.push(task);
                    }
                } 
            totalTime+= !pq.empty() ? cycle : time;
        }
        return totalTime;
    }
};