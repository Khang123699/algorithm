class Solution {
public:
    bool judgeSquareSum(int c) {
        long long leftNumber = 0;
        long long rightNumber = sqrt(c);
        while (leftNumber <= rightNumber) {
            long long currentSum = leftNumber * leftNumber + rightNumber * rightNumber;
            if (currentSum == c) {
                return true;
            } else if (currentSum < c) {
                leftNumber++;
            } else {
                rightNumber--;
            }
        }
        return false;
    }
};