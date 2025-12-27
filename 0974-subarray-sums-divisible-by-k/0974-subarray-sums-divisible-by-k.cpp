class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;

        unordered_map<int, int> m;
        m[0] = 1;

        int prefixSum = 0;

        for(auto i : nums) {

            prefixSum += i;

            int remainder = prefixSum % k;
            if(remainder < 0) {
                remainder += k;
            }

            if(m.count(remainder)) {
                ans += m[remainder];
            }

            m[remainder]++;
        }

        return ans;
    }
};