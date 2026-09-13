class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int totalElements = nums.size();
        vector<int> suffixMinimums(totalElements);
        suffixMinimums[totalElements - 1] = nums[totalElements - 1];
        for (int currentIndex = totalElements - 2; currentIndex >= 0; currentIndex--) {
            suffixMinimums[currentIndex] = min(nums[currentIndex], suffixMinimums[currentIndex + 1]);
        }
        int runningMaximum = nums[0];
        for (int currentIndex = 0; currentIndex < totalElements; currentIndex++) {
            runningMaximum = max(runningMaximum, nums[currentIndex]);
            int instabilityScore = runningMaximum - suffixMinimums[currentIndex];
            if (instabilityScore <= k) {
                return currentIndex;
            }
        }
        return -1;
    }
};