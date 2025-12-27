class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0;

        unordered_map<int, int> m;
        m[0] = -1;

        int prefixSum = 0;

        for(int i = 0; i < nums.size(); i++) {
            prefixSum += (nums[i] == 0) ? -1 : 1;

            if(m.count(prefixSum)) {
                ans = max(ans, i - m[prefixSum]);
            } 

            if(!m.count(prefixSum)) {
                m[prefixSum] = i;
            }
        }

        return ans;
    }
};