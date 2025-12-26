class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;

        unordered_map<int,int> m;
        m[0] = 1;
        int prefixSum = 0;

        for(int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            int search = prefixSum - k;

            if(m.find(search) != m.end()) {
                ans += m[search];
            }

            m[prefixSum]++;
        }

        return ans;
    }
};