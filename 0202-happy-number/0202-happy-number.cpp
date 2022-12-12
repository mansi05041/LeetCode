class Solution {
public:
    int getVal(int n){
        int s=0;
        while(n>0){
            int d=n%10;
            n=n/10;
            s+=d*d;
        }
        return s;
    }
    bool isHappy(int n) {
        // use set to store the value
        set<int> val;
        while(!val.count(n)){
            val.insert(n);
            n=getVal(n);
            if(n==1) return true;
        }
        return false;
    }
};