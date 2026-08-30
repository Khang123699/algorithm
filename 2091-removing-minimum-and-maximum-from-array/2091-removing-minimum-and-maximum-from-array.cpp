class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int totalElements = nums.size();
        int minimumIndex = 0;
        int maximumIndex = 0;
        for (int currentIndex = 1; currentIndex < totalElements; currentIndex++) {
            if (nums[currentIndex] < nums[minimumIndex]) {
                minimumIndex = currentIndex;
            }
            if (nums[currentIndex] > nums[maximumIndex]) {
                maximumIndex = currentIndex;
            }
        }
        int leftIndex = min(minimumIndex, maximumIndex);
        int rightIndex = max(minimumIndex, maximumIndex);
        int removeFromFront = rightIndex + 1;
        int removeFromBack = totalElements - leftIndex;
        int removeFromBothEnds = (leftIndex + 1) + (totalElements - rightIndex);
        return min({removeFromFront, removeFromBack, removeFromBothEnds});
    }
};