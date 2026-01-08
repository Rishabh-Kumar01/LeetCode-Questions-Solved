class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0;

        int n = nums.size();
        int s = 0;
        int e = 0;

        deque<int> maxDq;
        deque<int> minDq;

        while(e < n) {

            while(!maxDq.empty() && nums[maxDq.back()] < nums[e]) {
                maxDq.pop_back();
            }
            maxDq.push_back(e);

            while(!minDq.empty() && nums[minDq.back()] > nums[e]) {
                minDq.pop_back();
            }
            minDq.push_back(e);

            while((abs(nums[maxDq.front()] - nums[minDq.front()])) > limit) {
                s++;

                if (maxDq.front() < s) {
                    maxDq.pop_front();
                }
                if (minDq.front() < s) {
                    minDq.pop_front();
                }
            }

            ans = max(ans, e - s + 1);
            e++;
        }

        return ans;
    }
};