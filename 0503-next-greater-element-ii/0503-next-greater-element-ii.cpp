class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for(int i = 0; i < 2*n; i++) {

            int currIndex = i % n;

            while(!st.empty() && nums[currIndex] > nums[st.top()]) {
                ans[st.top()] = nums[currIndex];
                st.pop();
            }

            st.push(currIndex);
        }

        return ans;
    }
};