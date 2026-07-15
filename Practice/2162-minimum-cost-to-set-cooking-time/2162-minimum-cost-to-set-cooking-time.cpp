class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        auto calculateCost = [&](int targetMinutes, int targetSecondsRemaining) {
            if (targetMinutes < 0 || targetMinutes > 99 || targetSecondsRemaining < 0 || targetSecondsRemaining > 99) {
                return INT_MAX;
            }   
            string timeString = to_string(targetMinutes * 100 + targetSecondsRemaining);
            int totalCost = 0;
            char currentFinger = (char)(startAt + '0'); 
            for (char targetDigit : timeString) {
                if (targetDigit != currentFinger) {
                    totalCost += moveCost;
                    currentFinger = targetDigit;
                }
                totalCost += pushCost;
            } 
            return totalCost;
        };
        int baseMinutes = targetSeconds / 60;
        int baseSeconds = targetSeconds % 60;
        return min(calculateCost(baseMinutes, baseSeconds), 
                   calculateCost(baseMinutes - 1, baseSeconds + 60));
    }
};