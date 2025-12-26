class Solution {
public:
    int cntSubArraySum(const vector<int> temp, const int target) {
        unordered_map<int, int> m;
        m.reserve(temp.size() + 1);
        m[0] = 1;

        int cnt = 0;
        int prefixSum = 0;

        for(auto i : temp) {
            prefixSum += i;

            cnt += m[prefixSum - target];

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

                for(int col = 0; col < n; col++) {
                    temp[col] += matrix[bottom][col];
                }

                ans += cntSubArraySum(temp, target);
            }
        }

        return ans;
    }
};