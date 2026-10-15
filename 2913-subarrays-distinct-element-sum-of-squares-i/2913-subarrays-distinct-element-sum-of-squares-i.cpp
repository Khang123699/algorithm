class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int arrayLength = nums.size();
        int totalSumOfSquares = 0;
        for (int startIndex = 0; startIndex < arrayLength; startIndex++) {
            unordered_set<int> distinctElements;
            for (int endIndex = startIndex; endIndex < arrayLength; endIndex++) {
                distinctElements.insert(nums[endIndex]);
                int distinctCount = distinctElements.size();
                totalSumOfSquares += (distinctCount * distinctCount);
            }
        }
        return totalSumOfSquares;
    }
};