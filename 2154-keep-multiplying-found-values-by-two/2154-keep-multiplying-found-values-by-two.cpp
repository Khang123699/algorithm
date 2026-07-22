class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        for (int currentNumber : nums) {
            if (currentNumber == original) {
                original *= 2;
            }
        }  
        return original;
    }
};