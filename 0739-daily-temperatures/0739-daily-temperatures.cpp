class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> monoStack;

        for(int i = 0; i < n; i++) {

            while(!monoStack.empty() && temperatures[i] > temperatures[monoStack.top()]) {
                int days = i - monoStack.top();
                ans[monoStack.top()] = days;
                monoStack.pop();
            }

            monoStack.push(i);
        }

        return ans;
    }
};