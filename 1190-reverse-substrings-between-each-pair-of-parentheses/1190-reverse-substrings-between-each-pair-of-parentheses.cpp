class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> startIndexStack;
        string resultString = "";
        for (char currentCharacter : s) {
            if (currentCharacter == '(') {
                startIndexStack.push(resultString.length());
            } else if (currentCharacter == ')') {
                int startIndex = startIndexStack.top();
                startIndexStack.pop();
                reverse(resultString.begin() + startIndex, resultString.end());
            } else {
                resultString += currentCharacter;
            }
        }
        return resultString;
    }
};