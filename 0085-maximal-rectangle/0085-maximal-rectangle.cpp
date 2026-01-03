class Solution {
public:
    int maxArea(vector<int> heights) {
        int ans = 0;

        stack<int> st;

        int n = heights.size();

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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int area = 0;

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> heights(n,0);

        for(int i = 0; i < m; i++) {
            

            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') heights[j] += 1;
                else heights[j] = 0;
            }

            area = max(area, maxArea(heights));
        }

        return area;
    }
};