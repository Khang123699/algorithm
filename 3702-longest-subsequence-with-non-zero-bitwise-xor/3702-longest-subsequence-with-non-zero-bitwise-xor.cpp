class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXor = 0;
        int zeroCount = 0;
        int totalNumbers = nums.size();
        for (int currentNumber : nums) {
            totalXor ^= currentNumber;  
            if (currentNumber == 0) {
                zeroCount++;
            }
        }
        if (totalXor != 0) {
            return totalNumbers;
        }
        if (zeroCount == totalNumbers) {
            return 0;
        }
        return totalNumbers - 1;
    }
};