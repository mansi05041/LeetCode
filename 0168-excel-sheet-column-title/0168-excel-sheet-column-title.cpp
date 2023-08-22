class Solution {
public:
    string convertToTitle(int col) {
        string res = "";
        while(col){
            col--; // mapping to 0 based indexing
            res= res+(char)((col)%26+'A');
            col=col/26;
        }
        
        // reverse the string
        reverse(res.begin(),res.end());
        return res;
    }
};