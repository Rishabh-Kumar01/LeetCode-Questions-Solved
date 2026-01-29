class Solution {
public:
    void helper(vector<int> &input, const int &target, vector<vector<int>> &ans, vector<int> &curr, int sum, int idx){

        if(sum > target) return;

        if(sum == target) {
            ans.push_back(curr);
            return;
        }

        for(int i = max(0, idx); i < input.size(); i++){
            curr.push_back(input[i]);
            sum += input[i];

            helper(input, target, ans, curr, sum, i);

            curr.pop_back();
            sum -= input[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        helper(candidates, target, ans, curr, 0, 0);

        return ans;
    }
};