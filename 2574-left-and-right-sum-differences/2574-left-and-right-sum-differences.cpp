class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int arrayLength = nums.size();
        vector<int> answer(arrayLength);
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        for (int currentIndex = 0; currentIndex < arrayLength; currentIndex++) {
            rightSum -= nums[currentIndex];
            answer[currentIndex] = abs(leftSum - rightSum);
            leftSum += nums[currentIndex];
        }
        return answer;
    }
};