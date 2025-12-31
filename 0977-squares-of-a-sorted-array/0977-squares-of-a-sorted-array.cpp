class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        int idx = n-1;

        int s = 0;
        int e = n-1;

        vector<int> ans(n,0);

        while(s <= e) {
            long long int x = (long long int)(nums[s] * nums[s]);
            long long int y = (long long int)(nums[e] * nums[e]);

            if(x >= y) {
                ans[idx] = x;
                s++;
                idx--;
            } else {
                ans[idx] = y;
                e--;
                idx--;
            }

        }

        return ans;
    }
};