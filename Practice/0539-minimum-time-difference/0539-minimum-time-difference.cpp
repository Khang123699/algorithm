class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        if (timePoints.size()>1440) {
            return 0;
        }
        vector<int> minutes;
        for (string time:timePoints) {
            int h = stoi(time.substr(0,2));
            int m = stoi(time.substr(3,2));
            minutes.push_back(h*60+m);
        }
        sort(minutes.begin(),minutes.end());
        int min_diff = 1440;
        for (int i=1;i<minutes.size();++i) {
            min_diff = min(min_diff,minutes[i]-minutes[i-1]);
        }
        int circular_diff = 1440 - minutes.back() + minutes.front();
        min_diff = min(min_diff,circular_diff);
        return min_diff;
    }
};