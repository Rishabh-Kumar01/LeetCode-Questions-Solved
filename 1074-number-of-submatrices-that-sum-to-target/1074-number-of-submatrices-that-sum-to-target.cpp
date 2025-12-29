class Solution {
public:
    int cntSubArraySum(vector<int> nums, int k) {
        int cnt = 0;
        
        unordered_map<int, int> m;
        m[0] = 1;

        int prefixSum = 0;

        for(auto i : nums) {
            prefixSum += i;

            if(m.count(prefixSum - k)) {
                cnt += m[prefixSum - k];
            }

            m[prefixSum]++;
        }

        return cnt;
    }

    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0;

        int m = matrix.size();
        int n = matrix[0].size();

        for(int top = 0; top < m; top++) {
            vector<int> temp(n, 0);

            for(int bottom = top; bottom < m; bottom++) {
                

                for(int col = 0; col < n; col++) temp[col] += matrix[bottom][col];

                ans += cntSubArraySum(temp, target);
            }
        }

        return ans;
    }
};