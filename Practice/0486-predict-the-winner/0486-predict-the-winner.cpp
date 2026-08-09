class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int totalNumbers = nums.size();
        vector<int> scoreDifference = nums;
        for (int leftIndex = totalNumbers - 1; leftIndex >= 0; leftIndex--) {
            for (int rightIndex = leftIndex + 1; rightIndex < totalNumbers; rightIndex++) {
                int pickLeft = nums[leftIndex] - scoreDifference[rightIndex];
                int pickRight = nums[rightIndex] - scoreDifference[rightIndex - 1];
                scoreDifference[rightIndex] = max(pickLeft, pickRight);
            }
        }
        return scoreDifference[totalNumbers - 1] >= 0;
    }
};