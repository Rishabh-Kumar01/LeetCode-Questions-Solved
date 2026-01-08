class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        deque<int> dq;

        for(int i = 0; i < n; i++) {
            
            while(!dq.empty() && dq.front() < i - k) dq.pop_front();

            int maxPrev = dq.empty() ? 0 : max(0, dp[dq.front()]);
            dp[i] = nums[i] + maxPrev;

            while(!dq.empty() && dp[dq.back()] < dp[i]) dq.pop_back();

            dq.push_back(i);
        }

        return *max_element(dp.begin(), dp.end());
    }
};