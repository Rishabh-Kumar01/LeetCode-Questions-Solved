class Solution {
public:
    void helper(vector<int> &input, const int &k, const int &n, vector<int> &curr, vector<vector<int>> &ans, int sum, int idx) {

        if(sum > n) return;

        if(curr.size() > k) return;

        if(sum == n && curr.size() == k) {
            ans.push_back(curr);
            return;
        }

        for(int i = idx; i < input.size(); i++) {

            if(i > idx && input[i] == input[i-1]) continue;

            curr.push_back(input[i]);
            sum += input[i];

            helper(input, k, n, curr, ans, sum, i+1);

            curr.pop_back();
            sum -= input[i];
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;

        vector<int> input;

        for(int i = 1; i <= 9; i++) input.push_back(i);

        helper(input, k, n, curr, ans, 0, 0);

        return ans;
    }
};