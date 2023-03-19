class Solution {
public:
    int compress(vector<char>& chars) {
        int newIndex = 0;
        int count =1;
        int i;
        int size = chars.size();
        
        for(i=1;i<chars.size();i++){
            if(chars[i-1]==chars[i]){
                count++;
            }
            else{
                // put the char into resultant vector
                chars[newIndex]=chars[i-1];
                newIndex++;
                if(count>1){
                    string CountStr = to_string(count);
                    for(int j=0;j<CountStr.length();j++,newIndex++){
                        chars[newIndex]=CountStr[j];
                    }
                count=1;
                }
            }
        }
        
        // for last group
        chars[newIndex]=chars[i-1];
        newIndex++;
        if(count>1){
            string CountStr = to_string(count);
            for(int j=0;j<CountStr.length();j++,newIndex++) chars[newIndex]=CountStr[j];
        }
        
        chars.erase(chars.begin()+newIndex, chars.end());
        
        return(newIndex);
    }
};