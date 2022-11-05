class Solution {
public:

    // function to find the previous smallest element's index
    vector<int> PreviousSmallest(vector<int>& heights){
        vector<int> result(heights.size());
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            // remove the index till we find the smaller element's index on left side
            while(st.empty()==false && heights[i]<=heights[st.top()]) st.pop();
            // if the stack is empty , there is no smaller element 
            if(st.empty()) result[i]=-1;
            else result[i]=st.top();
            // push the current index into stack
            st.push(i);
        }
        return(result);
    }
    
    // function to find next smallest element's index
    vector<int> NextSmallest(vector<int>& heights){
        vector<int> result(heights.size());
        stack<int> st;
        for(int i=heights.size()-1;i>-1;i--){
            // remove the index till we find the smaller element's index on right side
            while(st.empty()==false && heights[i]<=heights[st.top()]) st.pop();
            // if the stack is empty , there is no smaller element 
            if(st.empty()) result[i]=heights.size();
            else result[i]=st.top();
            // push the current index into stack
            st.push(i);
        }
        return(result);
    }
    
    // function to find largest Rectangle Area
    int largestRectangleArea(vector<int>& heights) {
        vector<int> PS = PreviousSmallest(heights);
        vector<int> NS = NextSmallest(heights);
        int largestArea=0;
        for(int i=0;i<heights.size();i++){
            largestArea=max(largestArea,(NS[i]-PS[i]-1)*heights[i]);
        }
        return(largestArea);
    }

};