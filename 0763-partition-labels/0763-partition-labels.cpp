class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastOccurrence(26, 0);
        int stringLength = s.length();
        for (int currentIndex = 0; currentIndex < stringLength; currentIndex++) {
            lastOccurrence[s[currentIndex] - 'a'] = currentIndex;
        }
        vector<int> partitionsResult;
        int currentPartitionStart = 0;
        int currentPartitionEnd = 0;
        for (int currentIndex = 0; currentIndex < stringLength; currentIndex++) {
            int characterLastPosition = lastOccurrence[s[currentIndex] - 'a'];
            if (characterLastPosition > currentPartitionEnd) {
                currentPartitionEnd = characterLastPosition;
            }
            if (currentIndex == currentPartitionEnd) {
                partitionsResult.push_back(currentPartitionEnd - currentPartitionStart + 1);
                currentPartitionStart = currentIndex + 1;
            }
        }
        return partitionsResult;
    }
};