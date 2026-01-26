class Solution {
public:
    void helper(vector<int>& nums, vector<int>& curr, int start,
                vector<vector<int>>& ans) {
        ans.push_back(curr);

        for (int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            helper(nums, curr, i + 1, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        helper(nums, curr, 0, ans);

        return ans;
    }
};