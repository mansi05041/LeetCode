class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>> grp;
       for(int i=0;i<strs.size();i++){
           string temp = strs[i];
           sort(strs[i].begin(),strs[i].end());
           grp[strs[i]].push_back(temp);
       }
       vector<vector<string>> result;
       for(auto itr=grp.begin();itr!=grp.end();itr++){
           result.push_back(itr->second);
       }
        return(result);
    }
};