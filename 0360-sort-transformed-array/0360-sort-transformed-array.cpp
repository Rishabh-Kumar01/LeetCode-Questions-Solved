class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        
        int n = nums.size();

        vector<int> ans(n,0);

        int idx = 0;

        if(a >= 0) {
            idx = n-1;
        }

        int s = 0;
        int e = n-1;

        while(s <= e) {
            int x = (a * nums[s] * nums[s]) + (b * nums[s]) + c;
            int y = (a * nums[e] * nums[e]) + (b * nums[e]) + c;

            if(a >= 0) {
                if(x >= y) {
                    ans[idx] = x;
                    s++;
                } else {
                    ans[idx] = y; 
                    e--;
                }
                idx--;
            } else {
                if(x >= y) {
                    ans[idx] = y;
                    e--;
                } else {
                    ans[idx] = x;
                    s++;
                }
                idx++;
            }
        }

        return ans;
    }
};