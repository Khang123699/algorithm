class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimumPrice = INT_MAX;
        int maximumProfit = 0;
        for (int currentPrice : prices) {
            minimumPrice = min(minimumPrice, currentPrice);
            maximumProfit = max(maximumProfit, currentPrice - minimumPrice);
        }
        return maximumProfit;
    }
};