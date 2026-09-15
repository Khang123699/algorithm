class Solution {
public:
    int smallestNumber(int n, int t) {
        int currentNumber = n;
        while (true) {
            int digitProduct = 1;
            int temporaryNumber = currentNumber;
            while (temporaryNumber > 0) {
                digitProduct *= (temporaryNumber % 10);
                temporaryNumber /= 10;
            }
            if (digitProduct % t == 0) {
                return currentNumber;
            }
            currentNumber++;
        }
    }
};