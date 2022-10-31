class Solution {
public:
    bool isValid(string s) {
     stack<char> valid;
     
     for(auto x: s){
         if(valid.empty()) valid.push(x);
         else if(((x==')' && valid.top()=='('))|| ((x==']' && valid.top()=='['))|| ((x=='}' && valid.top()=='{'))) {
             valid.pop();
         }
         else valid.push(x);
     }
        return valid.empty();
    }
};