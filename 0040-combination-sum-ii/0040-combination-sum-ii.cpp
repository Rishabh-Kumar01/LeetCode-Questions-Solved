class Solution {
public:
    void helper(vector<int> &input, int target, vector<int> &curr, vector<vector<int>> &ans, int sum, int idx) {

        if(sum > target) return;

        if(sum == target) {
            ans.push_back(curr);
            return;
        }

        for(int i = idx; i < input.size(); i++){

            if(i > idx && input[i] == input[i-1]) continue;

            curr.push_back(input[i]);
            sum += input[i];

            helper(input, target, curr, ans, sum, i+1);

            curr.pop_back();
            sum -= input[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;

        helper(candidates, target, curr, ans, 0, 0);

        return ans;
    }
};