class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sortedNumbers = nums;
        sort(sortedNumbers.begin(), sortedNumbers.end());
        int totalNumbers = nums.size();
        int smallHalfIndex = (totalNumbers - 1) / 2;
        int largeHalfIndex = totalNumbers - 1;
        for (int currentIndex = 0; currentIndex < totalNumbers; currentIndex++) {
            if (currentIndex % 2 == 0) {
                nums[currentIndex] = sortedNumbers[smallHalfIndex];
                smallHalfIndex--;
            } else {
                nums[currentIndex] = sortedNumbers[largeHalfIndex];
                largeHalfIndex--;
            }
        }
    }
};