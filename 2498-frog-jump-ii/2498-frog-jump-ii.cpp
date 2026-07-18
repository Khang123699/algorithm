class Solution {
public:
    int maxJump(vector<int>& stones) {
        if (stones.size() == 2) {
            return stones[1] - stones[0];
        }
        int maximumCost = 0;
        for (int currentIndex = 2; currentIndex < stones.size(); currentIndex++) {
            int currentCost = stones[currentIndex] - stones[currentIndex - 2];
            
            if (currentCost > maximumCost) {
                maximumCost = currentCost;
            }
        }
        return maximumCost;
    }
};