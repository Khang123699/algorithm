class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
       unordered_set<int> existingNumbers;
        int minimumValue = nums[0];
        int maximumValue = nums[0];
        for (int currentNumber : nums) {
            existingNumbers.insert(currentNumber);
            if (currentNumber < minimumValue) {
                minimumValue = currentNumber;
            }
            if (currentNumber > maximumValue) {
                maximumValue = currentNumber;
            }
        }
        vector<int> missingElementsResult;
        for (int currentTarget = minimumValue + 1; currentTarget < maximumValue; currentTarget++) {
            if (existingNumbers.count(currentTarget) == 0) {
                missingElementsResult.push_back(currentTarget);
            }
        }
        return missingElementsResult;
    }
};