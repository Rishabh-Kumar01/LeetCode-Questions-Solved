class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = -1;

        int prefixSum = 0;

        for(int i = 0; i < nums.size(); i++) {

            prefixSum += nums[i];

            int remainder = prefixSum % k;

            if(m.count(remainder)) {
                int len = i - m[remainder];
                if(len >= 2) return true;
            } else {
                m[remainder] = i;
            }
        }


        return false;
    }
};