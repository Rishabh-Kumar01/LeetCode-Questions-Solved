class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;

        int n = heights.size();
        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && heights[i] < heights[st.top()]) {
                int idx = st.top();
                st.pop();

                int nse_index = i;
                int pse_index = st.empty() ? -1 : st.top();

                int area = heights[idx] * (nse_index - pse_index - 1);

                ans = max(ans, area);
            }

            st.push(i);
        }

        while(!st.empty()) {
            int idx = st.top();
            st.pop();

            int nse_index = n;
            int pse_index = st.empty() ? -1 : st.top();

            int area = heights[idx] * (nse_index - pse_index - 1);
            ans = max(ans, area);

        }

        return ans;
    }
};