
class LRUCache {
public:
    
    class Node{
public:
    int val;
    int key;
    Node* prev;
    Node* next;
    
    Node(int key,int val){
        this->key = key;
        this->val = val;
    }
};
    
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int,Node*> mp;
    int size;
    
    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    // add the node in the front of the linked list
    void addNode(Node* newNode){
        newNode->prev = head;
        newNode->next = head->next;
        head->next->prev = newNode;        
        head->next = newNode;
        
    }
    
    // delete the node in the end of the linked list
    void deleteNode(Node* delNode){
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
        // delete delNode;
    }
    
    int get(int key) {
        // find if it is present in the map
        if(mp.find(key)!=mp.end()){
            // present in the map, means we have use it 
            Node* getNode = mp[key];
            int val = getNode->val;
            // the node becomes recently used
            deleteNode(getNode);
            mp.erase(key);
            addNode(getNode);
            mp[key] = head->next;
            return val;
        }
        return -1; // not present
    }
    
    void put(int key, int value) {
        // find if it is present in the map
        if(mp.find(key)!=mp.end()){
            // remove it from map
            Node* existNode = mp[key];
            deleteNode(existNode);
            mp.erase(key);
        }
        
        // if the size exceeds
        else if(size==mp.size()){
            // remove the least recently used
            Node* delNode = tail->prev;
            deleteNode(delNode);
            mp.erase(delNode->key);
        }
    
        addNode(new Node(key,value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */