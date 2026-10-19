class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int lessThanCount = 0;
        int equalCount = 0;
        for (int currentNumber : nums) {
            if (currentNumber < target) {
                lessThanCount++;
            } else if (currentNumber == target) {
                equalCount++;
            }
        }
        vector<int> resultIndices;
        for (int indexOffset = 0; indexOffset < equalCount; indexOffset++) {
            resultIndices.push_back(lessThanCount + indexOffset);
        }
        return resultIndices;
    }
};