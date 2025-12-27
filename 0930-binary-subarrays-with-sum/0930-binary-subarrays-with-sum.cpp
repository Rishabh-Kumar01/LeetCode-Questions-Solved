class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;

        unordered_map<int, int> m;
        m[0] = 1;

        int prefixSum = 0;

        for(auto i : nums) {

            prefixSum += i;

            int lookup = prefixSum - goal;

            if(m.count(lookup)) {
                ans += m[lookup];
            }

            m[prefixSum]++;
        }

        return ans;
    }
};