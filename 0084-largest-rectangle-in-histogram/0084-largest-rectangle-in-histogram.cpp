class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
           
       stack<int> st; // create an empty stack
       int max_area=0; // initializa maximum area
       int top_st; // it stores the top of stack
       int top_area; // store the area of the top bar
       
       int i=0;
       while(i<heights.size()){
       
         // push the index into stack if stack is empty or the bar is higher than the top of stack
         if(st.empty() || heights[st.top()] <= heights[i]) st.push(i++);
         
         else{
            top_st = st.top();
            st.pop();
            top_area=heights[top_st]*(st.empty()? i: i-st.top()-1);
            
            // update the max area
            max_area=max(max_area,top_area);
         } 
      }
      
      // pop the remaining bars from stack and calculate the area with every popped bar
      while(st.empty()==false){
          top_st=st.top();
          st.pop();
          top_area=heights[top_st]*(st.empty()? i: i-st.top()-1);
          max_area = max(max_area,top_area);
      }
      
      return max_area;
        
    }
};