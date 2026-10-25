class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        string overlapStartDate = max(arriveAlice, arriveBob);
        string overlapEndDate = min(leaveAlice, leaveBob);
        if (overlapStartDate > overlapEndDate) {
            return 0;
        }
        vector<int> prefixDaysBeforeMonth = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        int startMonth = stoi(overlapStartDate.substr(0, 2));
        int startDay = stoi(overlapStartDate.substr(3, 2));
        int startDayOfYear = prefixDaysBeforeMonth[startMonth] + startDay;
        int endMonth = stoi(overlapEndDate.substr(0, 2));
        int endDay = stoi(overlapEndDate.substr(3, 2));
        int endDayOfYear = prefixDaysBeforeMonth[endMonth] + endDay;
        return endDayOfYear - startDayOfYear + 1;
    }
};