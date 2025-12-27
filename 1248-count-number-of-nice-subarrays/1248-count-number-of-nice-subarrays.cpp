class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0;

        unordered_map<int, int> m;
        m[0] = 1;

        int prefixSum = 0;

        for(auto i : nums) {

            prefixSum += (i % 2 == 0) ? 0 : 1;

            int lookup = prefixSum - k;

            if(m.count(lookup)) {
                ans += m[lookup];
            }

            m[prefixSum]++;
        }

        return ans;
    }
};