class Solution {
public:
    bool checkDivisibility(int n) {
       int originalNumber = n;
        int digitSum = 0;
        int digitProduct = 1;
        while (n > 0) {
            int currentDigit = n % 10;
            digitSum += currentDigit;
            digitProduct *= currentDigit;
            n /= 10;
        }
        int totalSum = digitSum + digitProduct;
        return originalNumber % totalSum == 0;
    }
};