class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minimumValue = nums1[0];
        bool hasOddNumber = false;
        for (int currentNumber : nums1) {
            if (currentNumber < minimumValue) {
                minimumValue = currentNumber;
            }
            if (currentNumber % 2 != 0) {
                hasOddNumber = true;
            }
        }
        if (minimumValue % 2 != 0) {
            return true;
        }
        return !hasOddNumber;
    }
};