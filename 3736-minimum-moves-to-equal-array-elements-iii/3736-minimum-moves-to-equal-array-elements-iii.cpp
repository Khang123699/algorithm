class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maximumElement = *max_element(nums.begin(), nums.end());
        int totalMoves = 0;
        
        for (int currentNumber : nums) {
            totalMoves += (maximumElement - currentNumber);
        }
        
        return totalMoves;
    }
};