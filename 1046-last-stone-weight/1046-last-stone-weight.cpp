class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // edge case: only one stone is there
        if(stones.size()==1) return stones[0];
        // Priority queue that store the heaviest stone in the top
        priority_queue<int> stone;
        for(auto it:stones){
            stone.push(it);
        }
        while(stone.size()>1){
            int HeaviestStone = stone.top();
            stone.pop();
            int SecondHeaviestStone = stone.top();
            stone.pop();
            if(HeaviestStone!=SecondHeaviestStone){
                HeaviestStone-=SecondHeaviestStone;
                stone.push(HeaviestStone);
            }
        }
        return stone.empty()? 0: stone.top();
    }
};