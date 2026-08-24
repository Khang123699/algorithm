class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> characterCounts(26, 0);
        int maximumLength = 0;
        int leftPointer = 0;
        int stringLength = s.length();
        for (int rightPointer = 0; rightPointer < stringLength; rightPointer++) {
            int currentCharacterIndex = s[rightPointer] - 'a';
            characterCounts[currentCharacterIndex]++;
            while (characterCounts[currentCharacterIndex] > 2) {
                int leftCharacterIndex = s[leftPointer] - 'a';
                characterCounts[leftCharacterIndex]--;
                leftPointer++;
            }
            int currentLength = rightPointer - leftPointer + 1;
            if (currentLength > maximumLength) {
                maximumLength = currentLength;
            }
        }
        return maximumLength;
    }
};