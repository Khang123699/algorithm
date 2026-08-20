class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> firstArray;
        vector<int> secondArray;
        firstArray.push_back(nums[0]);
        secondArray.push_back(nums[1]);
        int totalNumbers = nums.size();
        for (int currentIndex = 2; currentIndex < totalNumbers; currentIndex++) {
            if (firstArray.back() > secondArray.back()) {
                firstArray.push_back(nums[currentIndex]);
            } else {
                secondArray.push_back(nums[currentIndex]);
            }
        }
        vector<int> finalResult = firstArray;
        finalResult.insert(finalResult.end(), secondArray.begin(), secondArray.end());
        return finalResult;
    }
};