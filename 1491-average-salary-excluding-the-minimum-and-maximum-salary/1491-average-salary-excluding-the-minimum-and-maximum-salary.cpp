class Solution {
public:
    double average(vector<int>& salary) {
        int maximum_sal=-1;
        int minimum_sal=pow(10,6);
        int sum=0;
        int size=salary.size()-2;
        for(int i=0;i<salary.size();i++){
            if(maximum_sal<salary[i]) maximum_sal=salary[i];
            if(minimum_sal>salary[i]) minimum_sal=salary[i];
            sum+=salary[i];
        }
        sum=sum-(maximum_sal+minimum_sal);
        double avg=(double)sum/(double)size;
        return avg;
    }
};