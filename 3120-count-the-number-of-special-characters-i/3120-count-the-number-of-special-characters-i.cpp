class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> hasLowercase(26, false);
        vector<bool> hasUppercase(26, false);
        for (char currentCharacter : word) {
            if (currentCharacter >= 'a' && currentCharacter <= 'z') {
                hasLowercase[currentCharacter - 'a'] = true;
            } else if (currentCharacter >= 'A' && currentCharacter <= 'Z') {
                hasUppercase[currentCharacter - 'A'] = true;
            }
        }
        int specialCharacterCount = 0;
        for (int alphabetIndex = 0; alphabetIndex < 26; alphabetIndex++) {
            if (hasLowercase[alphabetIndex] && hasUppercase[alphabetIndex]) {
                specialCharacterCount++;
            }
        }
        return specialCharacterCount;
    }
};