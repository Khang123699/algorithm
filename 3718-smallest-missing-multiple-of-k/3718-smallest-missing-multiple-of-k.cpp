class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> existingNumbers(nums.begin(), nums.end());
        int currentMultiple = k;
        while (existingNumbers.count(currentMultiple) > 0) {
            currentMultiple += k;
        }
        return currentMultiple;
    }
};