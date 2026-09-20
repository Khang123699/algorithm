class Solution {
public:
    int reverseDegree(string s) {
        int totalDegree = 0;
        int stringLength = s.length();
        for (int currentIndex = 0; currentIndex < stringLength; currentIndex++) {
            int stringPosition = currentIndex + 1;
            int reverseAlphabetPosition = 'z' - s[currentIndex] + 1;
            totalDegree += (stringPosition * reverseAlphabetPosition);
        }
        return totalDegree;
    }
};