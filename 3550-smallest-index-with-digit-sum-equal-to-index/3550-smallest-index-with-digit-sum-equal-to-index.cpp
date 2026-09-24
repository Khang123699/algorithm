class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int totalElements = nums.size();
        for (int currentIndex = 0; currentIndex < totalElements; currentIndex++) {
            int temporaryNumber = nums[currentIndex];
            int digitSum = 0;
            while (temporaryNumber > 0) {
                digitSum += temporaryNumber % 10;
                temporaryNumber /= 10;
            }
            if (digitSum == currentIndex) {
                return currentIndex;
            }
        }
        return -1;
    }
};