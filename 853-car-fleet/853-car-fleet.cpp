class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> pos_time;
        for(int i=0;i<position.size();i++){
            pos_time.emplace_back(position[i],static_cast<double>(target-position[i])/speed[i]);
        }
        sort(pos_time.begin(),pos_time.end());
        int car_fleet=0;
        double current=0;
        for(int i=position.size()-1;i>=0;i--){
            if(pos_time[i].second>current){
                current=pos_time[i].second;
                ++car_fleet;
            }
        }
        return(car_fleet);
    }
};