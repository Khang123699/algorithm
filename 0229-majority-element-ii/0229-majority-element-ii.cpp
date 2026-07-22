class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidateOne = 0;
        int candidateTwo = 1;
        int countOne = 0;
        int countTwo = 0;
        for (int currentNumber : nums) {
            if (currentNumber == candidateOne) {
                countOne++;
            } else if (currentNumber == candidateTwo) {
                countTwo++;
            } else if (countOne == 0) {
                candidateOne = currentNumber;
                countOne = 1;
            } else if (countTwo == 0) {
                candidateTwo = currentNumber;
                countTwo = 1;
            } else {
                countOne--;
                countTwo--;
            }
        }
        countOne = 0;
        countTwo = 0;
        for (int currentNumber : nums) {
            if (currentNumber == candidateOne) {
                countOne++;
            } else if (currentNumber == candidateTwo) {
                countTwo++;
            }
        }
        vector<int> majorityElementsResult;
        int minimumThreshold = nums.size() / 3;
        if (countOne > minimumThreshold) {
            majorityElementsResult.push_back(candidateOne);
        }
        if (countTwo > minimumThreshold) {
            majorityElementsResult.push_back(candidateTwo);
        }
        return majorityElementsResult;
    }
};