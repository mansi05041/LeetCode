class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int flowerPlace =0;
        // put 0 at 0th index and last index
        flowerbed.push_back(0);
        flowerbed.insert(flowerbed.begin(),0);
        
        // we place the flower 
        for(int i=1;i<flowerbed.size()-1;i++){
            if(flowerbed[i]==0 && (flowerbed[i-1]==0 && flowerbed[i+1]==0)){
                flowerbed[i]=1;
                flowerPlace+=1;
            }
        }
      return(flowerPlace>=n);  
    }
};