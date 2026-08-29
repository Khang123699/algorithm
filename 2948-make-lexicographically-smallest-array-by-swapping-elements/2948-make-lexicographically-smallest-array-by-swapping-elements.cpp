class Solution {
public: vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    int totalElements = nums.size();
        vector<pair<int, int>> elementsWithIndex(totalElements);
        for (int currentIndex = 0; currentIndex < totalElements; currentIndex++) {
            elementsWithIndex[currentIndex] = {nums[currentIndex], currentIndex};
        }
        sort(elementsWithIndex.begin(), elementsWithIndex.end());
        vector<int> finalResult(totalElements);
        int groupStartIndex = 0;
        while (groupStartIndex < totalElements) {
            int groupEndIndex = groupStartIndex + 1;
            while (groupEndIndex < totalElements && elementsWithIndex[groupEndIndex].first - elementsWithIndex[groupEndIndex - 1].first <= limit) {
                groupEndIndex++;
            }
            vector<int> originalIndices;
            for (int currentIndex = groupStartIndex; currentIndex < groupEndIndex; currentIndex++) {
                originalIndices.push_back(elementsWithIndex[currentIndex].second);
            }
            sort(originalIndices.begin(), originalIndices.end());
            for (int currentIndex = 0; currentIndex < originalIndices.size(); currentIndex++) {
                finalResult[originalIndices[currentIndex]] = elementsWithIndex[groupStartIndex + currentIndex].first;
            }
            groupStartIndex = groupEndIndex;
        }
        return finalResult;
    }
};