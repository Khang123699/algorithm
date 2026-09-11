class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> availableDigits(10, 0);
        for (int currentDigit : digits) {
            availableDigits[currentDigit]++;
        }
        int distinctEvenCount = 0;
        for (int currentNumber = 100; currentNumber <= 998; currentNumber += 2) {
            int hundredsDigit = currentNumber / 100;
            int tensDigit = (currentNumber / 10) % 10;
            int unitsDigit = currentNumber % 10;
            availableDigits[hundredsDigit]--;
            availableDigits[tensDigit]--;
            availableDigits[unitsDigit]--;
            if (availableDigits[hundredsDigit] >= 0 && 
                availableDigits[tensDigit] >= 0 && 
                availableDigits[unitsDigit] >= 0) {
                distinctEvenCount++;
            }
            availableDigits[hundredsDigit]++;
            availableDigits[tensDigit]++;
            availableDigits[unitsDigit]++;
        }
        return distinctEvenCount;
    }
};