class Solution {
public:
    int maxArea(vector<int>& nums) {
        int ans = 0;

        int n = nums.size();

        int s = 0;
        int e = n-1;

        while(s < e) {
            int height = min(nums[s], nums[e]);
            int length = e-s;

            int area = height * length;

            ans = max(ans, area);

            if(nums[s] >= nums[e]) e--;
            else s++;
        }

        return ans;
    }
};