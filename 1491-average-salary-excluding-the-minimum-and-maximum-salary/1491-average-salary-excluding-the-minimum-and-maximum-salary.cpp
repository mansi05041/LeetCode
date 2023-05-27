class Solution {
public:
    double average(vector<int>& salary) {
        int minSal = salary[0];
        int maxSal = salary[0];
        int Sum = salary[0];
        for(int i=1;i<salary.size();i++){
            Sum+=salary[i];
            if(minSal>salary[i]) minSal = salary[i];
            if(maxSal<salary[i]) maxSal = salary[i];
        }
        return (double)(Sum-minSal-maxSal)/(double)(salary.size()-2);
    }
};