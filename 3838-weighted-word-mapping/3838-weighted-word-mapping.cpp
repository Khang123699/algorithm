class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string mappedResult = "";
        for (const string& currentWord : words) {
            int currentWordWeight = 0;
            for (char currentCharacter : currentWord) {
                currentWordWeight += weights[currentCharacter - 'a'];
            }
            int remainder = currentWordWeight % 26;
            char mappedCharacter = 'z' - remainder;
            mappedResult += mappedCharacter;
        }
        return mappedResult;
    }
};