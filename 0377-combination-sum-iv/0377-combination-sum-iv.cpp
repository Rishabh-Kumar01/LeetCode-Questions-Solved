class Solution {
public:
    int helper(vector<int> &input, int remaining, unordered_map<int, int> &memo) {

        if(remaining == 0) return 1;

        if(remaining < 0) return 0;

        if(memo.find(remaining) != memo.end()){
            return memo[remaining];
        }

        int ways = 0;

        for(auto i : input) {
            ways += helper(input, remaining - i, memo);
        }

        memo[remaining] = ways;
        return ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int ans = 0;
        unordered_map<int, int> memo;

        return helper(nums, target, memo);
    }
};