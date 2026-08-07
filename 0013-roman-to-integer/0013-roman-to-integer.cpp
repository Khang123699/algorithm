class Solution {
public:
    int getRomanValue(char romanCharacter) {
        switch (romanCharacter) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
    int romanToInt(string s) {
        int integerResult = 0;
        int stringLength = s.length();
        for (int currentIndex = 0; currentIndex < stringLength; currentIndex++) {
            int currentValue = getRomanValue(s[currentIndex]);
            if (currentIndex + 1 < stringLength && currentValue < getRomanValue(s[currentIndex + 1])) {
                integerResult -= currentValue;
            } else {
                integerResult += currentValue;
            }
        }
        return integerResult;
    }
};