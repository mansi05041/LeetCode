class MyStack {
public:
    queue<int>* q;
    MyStack() {
      q = new queue<int>;
    }
    
    void push(int x) {
        int size=q->size();
        q->push(x); // insert at the top of stack
        while(size>0){
            q->push(q->front());
            q->pop();
            --size;
        }
    }
    
    int pop() {
        int res=top();
        q->pop();
        return res;
    }
    
    int top() {
        return q->front();
    }
    
    bool empty() {
        return q->empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */