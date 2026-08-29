class Solution {
public:
    bool sumGame(string num) {
        int stringLength = num.length();
        int halfLength = stringLength / 2;
        
        int firstHalfSum = 0;
        int firstHalfQuestionMarks = 0;
        int secondHalfSum = 0;
        int secondHalfQuestionMarks = 0;
        
        for (int currentIndex = 0; currentIndex < halfLength; currentIndex++) {
            if (num[currentIndex] == '?') {
                firstHalfQuestionMarks++;
            } else {
                firstHalfSum += num[currentIndex] - '0';
            }
        }
        
        for (int currentIndex = halfLength; currentIndex < stringLength; currentIndex++) {
            if (num[currentIndex] == '?') {
                secondHalfQuestionMarks++;
            } else {
                secondHalfSum += num[currentIndex] - '0';
            }
        }
        
        int totalQuestionMarks = firstHalfQuestionMarks + secondHalfQuestionMarks;
        
        if (totalQuestionMarks % 2 != 0) {
            return true;
        }
        
        int sumDifference = firstHalfSum - secondHalfSum;
        int questionMarkDifference = secondHalfQuestionMarks - firstHalfQuestionMarks;
        
        if (sumDifference * 2 != questionMarkDifference * 9) {
            return true;
        }
        
        return false;
    }
};