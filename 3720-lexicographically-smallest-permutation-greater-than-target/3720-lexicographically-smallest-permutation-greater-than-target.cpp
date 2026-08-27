class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> charCounts(26, 0);
        int stringLength = s.length();
        for (char currentCharacter : s) {
            charCounts[currentCharacter - 'a']++;
        }
        int matchLength = 0;
        while (matchLength < stringLength && charCounts[target[matchLength] - 'a'] > 0) {
            charCounts[target[matchLength] - 'a']--;
            matchLength++;
        }
        for (int k = matchLength; k >= 0; k--) {
            if (k < stringLength) {
                for (int nextCharIndex = target[k] - 'a' + 1; nextCharIndex < 26; nextCharIndex++) {
                    if (charCounts[nextCharIndex] > 0) {
                        string result = target.substr(0, k);
                        result += (char)(nextCharIndex + 'a');
                        charCounts[nextCharIndex]--;
                        
                        for (int i = 0; i < 26; i++) {
                            if (charCounts[i] > 0) {
                                result.append(charCounts[i], (char)(i + 'a'));
                            }
                        }
                        return result;
                    }
                }
            }
            if (k > 0) {
                charCounts[target[k - 1] - 'a']++;
            }
        }
        return "";
    }
};