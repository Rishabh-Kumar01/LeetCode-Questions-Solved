class Solution {
public:
    int kadane(vector<int> nums) {
        int sum = 0;
        int maxi = INT_MIN;

        for(auto i : nums) {
            if(sum < 0) sum = 0;

            sum += i;

            maxi = max(maxi, sum);
        }

        return maxi;
    }

    int kadaneMin(vector<int> nums) {
        int sum = 0;
        int mini = INT_MAX;

        for(auto i : nums) {
            if(sum > 0) sum = 0;

            sum += i;

            mini = min(mini, sum);
        }

        return mini;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int maxi = kadane(nums);

        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        int mini = kadaneMin(nums);

        if(maxi < 0) return maxi;

        return max(maxi, totalSum - mini);
    }
};