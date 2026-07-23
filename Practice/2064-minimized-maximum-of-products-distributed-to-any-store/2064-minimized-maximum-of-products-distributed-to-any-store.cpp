class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int leftBound = 1;
        int rightBound = 0;
        for (int currentQuantity : quantities) {
            if (currentQuantity > rightBound) {
                rightBound = currentQuantity;
            }
        }
        int minimizedMaximumValue = rightBound;
        while (leftBound <= rightBound) {
            int middleValue = leftBound + (rightBound - leftBound) / 2;
            long long requiredStores = 0;
            for (int currentQuantity : quantities) {
                requiredStores += (currentQuantity + middleValue - 1) / middleValue;
            }
            if (requiredStores <= n) {
                minimizedMaximumValue = middleValue;
                rightBound = middleValue - 1;
            } else {
                leftBound = middleValue + 1;
            }
        }
        return minimizedMaximumValue;
    }
};