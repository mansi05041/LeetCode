class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for(int i=0;i<asteroids.size();i++){
            
            bool Include = true;
            
            while(!st.empty() && (st.top()>0 && asteroids[i]<0)){
                
                // the top of stack is smaller than size, then it will explode
                if(abs(st.top())<abs(asteroids[i])){
                    st.pop();
                    continue;
                }
                   
                // if both are same size then both explode
                else if(abs(st.top())==abs(asteroids[i])) {
                    st.pop();
                }
                
                Include = false;
                break;
            }
                   
            if(Include) st.push(asteroids[i]);
        }
                   
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};