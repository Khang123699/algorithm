class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int totalElements = arr.size();
        vector<int> minimumLengthUpTo(totalElements, INT_MAX);
        int leftPointer = 0;
        int currentSum = 0;
        int minimumTotalLength = INT_MAX;
        int bestSingleLengthSoFar = INT_MAX;
        for (int rightPointer = 0; rightPointer < totalElements; rightPointer++) {
            currentSum += arr[rightPointer];
            while (currentSum > target && leftPointer <= rightPointer) {
                currentSum -= arr[leftPointer];
                leftPointer++;
            }
            if (currentSum == target) {
                int currentSubarrayLength = rightPointer - leftPointer + 1;
                if (leftPointer > 0 && minimumLengthUpTo[leftPointer - 1] != INT_MAX) {
                    minimumTotalLength = min(minimumTotalLength, currentSubarrayLength + minimumLengthUpTo[leftPointer - 1]);
                }
                bestSingleLengthSoFar = min(bestSingleLengthSoFar, currentSubarrayLength);
            }
            minimumLengthUpTo[rightPointer] = bestSingleLengthSoFar;
        }
        if (minimumTotalLength == INT_MAX) {
            return -1;
        }
        return minimumTotalLength;
    }
};