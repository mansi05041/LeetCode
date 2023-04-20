class Solution {
public:
    string simplifyPath(string path) { 
        // split the string
        vector<string> dirStack;
        stringstream ss(path);
        string dir;
        while(getline(ss,dir,'/')){
            // if the dirStack is not empty and dir is .. 
            if(!dirStack.empty() && dir=="..") dirStack.pop_back(); 
            // push the dir
            else if(dir!="." && dir!="" && dir!="..") dirStack.push_back(dir);
        }
        string result ="";
        for(auto it: dirStack){
            result+="/"+it;
        }
        return result==""? "/":result;
    }
};