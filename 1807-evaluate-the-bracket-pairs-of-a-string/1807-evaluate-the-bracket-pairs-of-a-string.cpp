class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> knowledgeMap;
        for (const vector<string>& currentPair : knowledge) {
            knowledgeMap[currentPair[0]] = currentPair[1];
        }
        string resultString = "";
        string currentKey = "";
        bool isInsideBracket = false;
        for (char currentCharacter : s) {
            if (currentCharacter == '(') {
                isInsideBracket = true;
                currentKey = "";
            } else if (currentCharacter == ')') {
                isInsideBracket = false;
                if (knowledgeMap.find(currentKey) != knowledgeMap.end()) {
                    resultString += knowledgeMap[currentKey];
                } else {
                    resultString += "?";
                }
            } else {
                if (isInsideBracket) {
                    currentKey += currentCharacter;
                } else {
                    resultString += currentCharacter;
                }
            }
        }
        return resultString;
    }
};