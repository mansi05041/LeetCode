class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // set to store the unique words
        set<string> wordSet(wordList.begin(),wordList.end());
        if(wordSet.find(endWord)==wordSet.end()) return 0; // the endWord is not present in the list
        
        // Queue for the bfs traversal
        queue<string> q;
        // push the beginWord into the queue
        q.push(beginWord);
        int depth=0; // used to get the depth of the traversal
        
        while(!q.empty()){
            depth++;  // the new level started
            int lsize = q.size();
            while(lsize--){
                // get the front word and pop it from queue
                auto curr = q.front();
                q.pop();
                // check all the possible transformation
                for(int i=0;i<curr.size();i++){
                    string temp = curr;
                    for(char ch='a';ch<='z';ch++){
                        temp[i]=ch;
                        // if same word found then skip it
                        if(curr.compare(temp)==0) continue;
                        if(temp.compare(endWord)==0) return depth+1;
                        // check if the new word is already present in the set
                        if(wordSet.find(temp)!=wordSet.end()){
                            q.push(temp);
                            wordSet.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};