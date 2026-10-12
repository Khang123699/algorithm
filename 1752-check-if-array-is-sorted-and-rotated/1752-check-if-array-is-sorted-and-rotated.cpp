class Solution {
public:
    bool check(vector<int>& nums) {
        int arrayLength = nums.size();
        int decreaseCount = 0;
        for (int currentIndex = 0; currentIndex < arrayLength; currentIndex++) {
            if (nums[currentIndex] > nums[(currentIndex + 1) % arrayLength]) {
                decreaseCount++;
            }
            if (decreaseCount > 1) {
                return false;
            }
        }
        return true;
    }
};