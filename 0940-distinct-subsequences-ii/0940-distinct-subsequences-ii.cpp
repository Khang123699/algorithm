class Solution {
public:
    int distinctSubseqII(string s) {
        long long modValue = 1000000007;
        vector<long long> endCounts(26, 0);
        long long currentTotal = 0;
        for (char currentCharacter : s) {
            int characterIndex = currentCharacter - 'a';
            long long previousCount = endCounts[characterIndex];
            long long newCount = (currentTotal + 1) % modValue;
            endCounts[characterIndex] = newCount;
            currentTotal = (currentTotal - previousCount + modValue) % modValue;
            currentTotal = (currentTotal + newCount) % modValue;
        }
        return currentTotal;
    }
};