class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int minLen = min(word1.size(),word2.size());
        string mergeStr = "";
        for(int i = 0;i<minLen;i++){
            mergeStr+=word1[i];
            mergeStr+=word2[i];
        }
        mergeStr+=word1.size()==minLen? "":word1.substr(minLen);
        mergeStr+=word2.size()==minLen? "":word2.substr(minLen);
        return(mergeStr);
    }
};