class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int lengthOne = num1.length();
        int lengthTwo = num2.length();
        vector<int> multiplicationResult(lengthOne + lengthTwo, 0);
        for (int indexOne = lengthOne - 1; indexOne >= 0; indexOne--) {
            for (int indexTwo = lengthTwo - 1; indexTwo >= 0; indexTwo--) {
                int digitOne = num1[indexOne] - '0';
                int digitTwo = num2[indexTwo] - '0';
                int currentProduct = digitOne * digitTwo;
                int currentPosition = indexOne + indexTwo + 1;
                int carryPosition = indexOne + indexTwo;
                int totalSum = currentProduct + multiplicationResult[currentPosition];
                multiplicationResult[currentPosition] = totalSum % 10;
                multiplicationResult[carryPosition] += totalSum / 10;
            }
        }
        string finalStringResult = "";
        bool hasLeadingZero = true;
        for (int currentDigit : multiplicationResult) {
            if (currentDigit != 0) {
                hasLeadingZero = false;
            }
            if (!hasLeadingZero) {
                finalStringResult += to_string(currentDigit);
            }
        }
        return finalStringResult;
    }
};