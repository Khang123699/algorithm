class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> subarrayOccurrences;
        int totalNumbers = nums.size();
        for (int startIndex = 0; startIndex <= totalNumbers - k; startIndex++) {
            unordered_set<int> currentSubarrayElements;
            for (int currentIndex = startIndex; currentIndex < startIndex + k; currentIndex++) {
                currentSubarrayElements.insert(nums[currentIndex]);
            }   
            for (int uniqueElement : currentSubarrayElements) {
                subarrayOccurrences[uniqueElement]++;
            }
        }
        int maximumAlmostMissing = -1;
        for (const auto& [element, occurrenceCount] : subarrayOccurrences) {
            if (occurrenceCount == 1) {
                if (element > maximumAlmostMissing) {
                    maximumAlmostMissing = element;
                }
            }
        }
        return maximumAlmostMissing;
    }
};