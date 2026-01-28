class Solution {
public:
    void helper(vector<int> &input, vector<vector<int>> &ans, int k, vector<int> &curr, int idx) {

        if(curr.size() == k) {
            ans.push_back(curr);
            return;
        }

        for(int i = idx; i < input.size(); i++) {
            curr.push_back(input[i]);
            helper(input, ans, k, curr, i+1);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> input;
        
        for(int i = 1; i <= n; i++) input.push_back(i);

        vector<vector<int>> ans;
        vector<int> curr;

        helper(input, ans, k, curr, 0);

        return ans;
    }
};