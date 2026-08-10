class Solution {
public:
    int minimumPushes(string word) {
        vector<int> letterFrequencies(26, 0);
        for (char currentCharacter : word) {
            letterFrequencies[currentCharacter - 'a']++;
        }
        sort(letterFrequencies.rbegin(), letterFrequencies.rend());
        int totalPushes = 0;
        for (int currentIndex = 0; currentIndex < 26; currentIndex++) {
            if (letterFrequencies[currentIndex] == 0) {
                break;
            } 
            int currentCostMultiplier = (currentIndex / 8) + 1;
            totalPushes += letterFrequencies[currentIndex] * currentCostMultiplier;
        }
        return totalPushes;
    }
};