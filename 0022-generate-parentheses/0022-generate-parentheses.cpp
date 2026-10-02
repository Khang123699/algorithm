class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> combinations;
        stack<tuple<string, int, int>> stateStack;
        stateStack.push({"", 0, 0});
        while (!stateStack.empty()) {
            auto [currentString, openCount, closedCount] = stateStack.top();
            stateStack.pop();
            if (currentString.length() == n * 2) {
                combinations.push_back(currentString);
                continue;
            }
            if (closedCount < openCount) {
                stateStack.push({currentString + ")", openCount, closedCount + 1});
            }
            if (openCount < n) {
                stateStack.push({currentString + "(", openCount + 1, closedCount});
            }
        }
        return combinations;
    }
};