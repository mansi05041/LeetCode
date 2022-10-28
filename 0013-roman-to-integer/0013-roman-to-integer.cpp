class Solution {
public:
    int romanToInt(string s) {
        map<char,int> roman;
        roman['M']=1000;
        roman['D']=500;
        roman['C']=100;
        roman['L']=50;
        roman['X']=10;
        roman['V']=5;
        roman['I']=1;
        int n=s.size();
        int result=roman[s[n-1]];
        for(int i=n-2; i>=0;i--){
            if(roman[s[i]]<roman[s[i+1]]) result-=roman[s[i]];
            else result+=roman[s[i]];
        }
        return result;
    }
};