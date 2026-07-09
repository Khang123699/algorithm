class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currentMaximum = nums[0];
        int currentMinimum = nums[0];
        int globalMaximum = nums[0];
        for (int currentIndex = 1; currentIndex < nums.size(); currentIndex++) {
            int currentNumber = nums[currentIndex];   
            if (currentNumber < 0) {
                swap(currentMaximum, currentMinimum);
            }   
            currentMaximum = max(currentNumber, currentMaximum * currentNumber);
            currentMinimum = min(currentNumber, currentMinimum * currentNumber);
            globalMaximum = max(globalMaximum, currentMaximum);
        }
        return globalMaximum;
    }
};