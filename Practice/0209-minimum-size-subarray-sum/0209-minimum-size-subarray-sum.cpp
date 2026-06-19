class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int n = nums.size();
        int min_len = INT_MAX;
        int left = 0;
        long long current_sum = 0;
        for (int right = 0; right < n; ++right) {
            current_sum += nums[right];
            while (current_sum >= target) {
                min_len = min(min_len, right - left + 1);
                current_sum -= nums[left];
                left++;
            }
        }
        if(min_len == INT_MAX){
            return 0;
        }else{
            return min_len;
        }
    }
};