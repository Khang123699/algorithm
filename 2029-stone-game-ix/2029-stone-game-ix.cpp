class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> remainderCounts(3, 0);
        for (int currentStoneValue : stones) {
            remainderCounts[currentStoneValue % 3]++;
        }
        if (remainderCounts[0] % 2 == 0) {
            return remainderCounts[1] > 0 && remainderCounts[2] > 0;
        } else {
            return abs(remainderCounts[1] - remainderCounts[2]) > 2;
        }
    }
};