class Solution {
public:
    int numDistinct(string s, string t) {
        int sourceLength = s.length();
        int targetLength = t.length();
        vector<unsigned long long> distinctCounts(targetLength + 1, 0);
        distinctCounts[0] = 1;
        for (int sourceIndex = 1; sourceIndex <= sourceLength; sourceIndex++) {
            for (int targetIndex = targetLength; targetIndex >= 1; targetIndex--) {
                if (s[sourceIndex - 1] == t[targetIndex - 1]) {
                    distinctCounts[targetIndex] += distinctCounts[targetIndex - 1];
                }
            }
        }
        return distinctCounts[targetLength];
    }
};