/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* currNode, Node* copyNode, vector<Node*> &visited){
        // mark the copyNode visited
        visited[copyNode->val]= copyNode;
        
        // Iterate for all the neighbors
        for(auto it: currNode->neighbors){
            // if the neighbor is not visited
            if(visited[it->val]==NULL){
                // create a copy of the neighbor and push it into copyNode neighbor list
                Node* newNode = new Node(it->val);
                (copyNode->neighbors).push_back(newNode);
                dfs(it,newNode,visited);
            }
            else{
                (copyNode->neighbors).push_back(visited[it->val]);
            }
        }
        
    }
    Node* cloneGraph(Node* node) {
        // boundary case
        if(node == NULL) return NULL;
        
        // visited array 
        vector<Node*> visited(101,NULL);
        
        // make the copy of given node and mark it visited
        Node* copy = new Node(node->val);
        visited[node->val] = copy;
        
        // Iterate for all the neighbors
        for(auto it: node->neighbors){
            // if the neighbor is not visited yet
            if(visited[it->val]==NULL){
                // create a new copy of the neighbor and push it into copy neighbor list
                Node* newNode = new Node(it->val);
                (copy->neighbors).push_back(newNode);
                dfs(it,newNode,visited);
            }
            else{
                (copy->neighbors).push_back(visited[it->val]);
            }
        }
        return copy;
    }
};