class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];
        int totalNumbers = nums.size();
        for (int currentIndex = 0; currentIndex < totalNumbers - 2; currentIndex++) {
            int leftPointer = currentIndex + 1;
            int rightPointer = totalNumbers - 1;
            while (leftPointer < rightPointer) {
                int currentSum = nums[currentIndex] + nums[leftPointer] + nums[rightPointer];
                if (abs(currentSum - target) < abs(closestSum - target)) {
                    closestSum = currentSum;
                }
                if (currentSum == target) {
                    return currentSum;
                } else if (currentSum < target) {
                    leftPointer++;
                } else {
                    rightPointer--;
                }
            }
        }
        return closestSum;
    }
};