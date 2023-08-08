class Solution {
public:
    int helper(string answerKey, int k, char ch){
        int start = 0;
        int end = 0;
        int maxSize = 0;
        int count = 0;
        
        while(end<answerKey.size()){
            if(answerKey[end]!=ch) count++;
            
            while(start<=end && count>k){
                if(answerKey[start]!=ch) count--;
                start++;
            }
            
            maxSize = max(maxSize,end-start+1);
            end++;
        }
        return maxSize;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(helper(answerKey,k,'T'),helper(answerKey,k,'F'));
    }
};