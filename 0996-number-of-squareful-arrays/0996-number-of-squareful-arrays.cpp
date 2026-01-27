class Solution {
public:
    bool isPerfectSquare(int n) {
        if (n < 0)
            return false;
        int root = std::sqrt(n);
        return (root * root == n);
    }

    void helper(vector<int>& nums, vector<int>& curr, int& ans,
                vector<bool>& used) {

        if (curr.size() == nums.size()) {
            ans += 1;
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (used[i])
                continue;

            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;

            if(!curr.empty() && !isPerfectSquare(curr.back() + nums[i])) continue;

            curr.push_back(nums[i]);
            used[i] = true;

            helper(nums, curr, ans, used);

            curr.pop_back();
            used[i] = false;
        }
    }
    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        vector<int> curr;
        vector<bool> used(nums.size(), false);

        helper(nums, curr, ans, used);

        return ans;
    }
};