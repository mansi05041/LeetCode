class MyQueue {
public:
    stack<int> st1,st2;
    // st1's top act as rear of queue
    // st2's top act as front of queue
    MyQueue() {
       
    }
    
    void push(int x) {
        st1.push(x); // push the element to the back of queue
    }
    
    int pop() {
        int res = peek();
        st2.pop();
        return res;
    }
    
    int peek() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int res = st2.top();
        return res;
    }
    
    bool empty() {
        return (st1.empty() && st2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */