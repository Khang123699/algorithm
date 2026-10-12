class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int arrayLength = nums.size();
        int totalSumOfSquares = 0;
        for (int currentIndex = 1; currentIndex <= arrayLength; currentIndex++) {
            if (arrayLength % currentIndex == 0) {
                int currentValue = nums[currentIndex - 1];
                totalSumOfSquares += (currentValue * currentValue);
            }
        }
        return totalSumOfSquares;
    }
};