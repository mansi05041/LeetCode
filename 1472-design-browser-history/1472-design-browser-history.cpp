class BrowserHistory {
public:
    stack<string> history,future;
    string current;
    BrowserHistory(string homepage) {
        // the first url is homepage
        current=homepage;
    }
    
    void visit(string url) {
        // push the url into history
        history.push(current);
        current=url;
        // clear the future stack
        future= stack<string>();
    }
    
    // pop elements from history and push in future
    string back(int steps) {
        while(steps>0 && !history.empty()){
            future.push(current);
            current= history.top();
            history.pop();
            steps--;
        }
        return current;
    }
    
    // pop elements from future and push in history 
    string forward(int steps) {
        while(steps>0 && !future.empty()){
            history.push(current);
            current = future.top();
            future.pop();
            steps--;
        }
        return current;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */