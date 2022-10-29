class Solution {
public:
    
    static bool comp(pair<int,int>p1,pair<int,int>p2){
        return(p1.second>p2.second);
    }
    
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        // used extra space to store the pair 
        vector<pair<int,int>> farm;
        for(int i=0;i<plantTime.size();i++){
            farm.push_back({plantTime[i],growTime[i]});
        }
        
        // sort the pair such that the highest growth time appears first
        sort(farm.begin(),farm.end(),comp);
        
        // start keeps the track of planttime 
        int start=0;
        int result=0;
        for(auto &x: farm){
            start+=x.first;
            result=max(result,start+x.second);
        }
        
        return(result);
        
    }
};