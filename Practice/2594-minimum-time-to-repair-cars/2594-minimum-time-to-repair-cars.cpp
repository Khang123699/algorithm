class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int minimumRank = ranks[0];
        for (int currentRank : ranks) {
            if (currentRank < minimumRank) {
                minimumRank = currentRank;
            }
        }
        long long leftBound = 1;
        long long rightBound = 1LL * minimumRank * cars * cars;
        long long minimumTime = rightBound;
        while (leftBound <= rightBound) {
            long long middleTime = leftBound + (rightBound - leftBound) / 2;
            long long totalRepairedCars = 0;
            for (int currentRank : ranks) {
                totalRepairedCars += sqrt(middleTime / currentRank);
            }
            if (totalRepairedCars >= cars) {
                minimumTime = middleTime;
                rightBound = middleTime - 1;
            } else {
                leftBound = middleTime + 1;
            }
        }
        return minimumTime;
    }
};