class MyCircularQueue {
public:
    vector<int> queue;
    int front;
    int rear;
    int size;
   
    MyCircularQueue(int k){
        queue.resize(k);
        front=-1;
        rear=-1;
        size=k;
    }
    
    bool enQueue(int value) {
        // case 1: if the queue is full ( no insertion possible)
        if(isFull()) return false;
        
        // case 2: if the queue is empty then set front and rear =0 
        if(rear==-1){
            front=rear=0;
        }
        
        // case 3: increment the rear for buffer
        else rear=(rear+1)%size;
        
        queue[rear]=value;
        return true;
    }
    
    bool deQueue() {
        // case1 : if the queue is empty (no insertion will take place)
        if(isEmpty()) return false;
        
        // case 2: if only one element is present in queue then set front and rear=-1
        if(front==rear){
            front=-1;
            rear=-1;
        }
        
        // case 3: increment the front 
        else front=(front+1)%size;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return(-1);
        return queue[front];
    }
    
    int Rear() {
        if(isEmpty()) return(-1);
        return queue[rear];
    }
    
    bool isEmpty() {
        return(front==-1);
    }
       
    
    bool isFull() {
        return front==0 && rear==size-1|| rear==front-1;   
    }
    
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */