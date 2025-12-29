class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        int k = total - x;

        if(k < 0) return -1;

        int n = nums.size();
        if(k == 0) return n;

        int ans = -1;

        unordered_map<int, int> m;
        m[0] = -1;

        int prefixSum = 0;

        for(int i = 0; i < n; i++) {

            prefixSum += nums[i];

            if(m.count(prefixSum - k)) {
                ans = max(ans, i - m[prefixSum - k]);
            }

            if(!m.count(prefixSum)) {
                m[prefixSum] = i;
            }
        }

        return ans == -1 ? -1 : (n-ans);
    }
};