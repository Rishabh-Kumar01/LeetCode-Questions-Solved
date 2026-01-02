class Solution {
public:
    int trap(vector<int>& nums) {
        int ans = 0;

        int n = nums.size();

        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && nums[i] > nums[st.top()]) {
                int bottom_index = st.top();
                st.pop();

                if(st.empty()) continue;

                int left_index = st.top();
                int right_index = i;

                int height = min(nums[left_index], nums[right_index]) - nums[bottom_index];
                int width = right_index - left_index - 1;
                ans += (height * width);
            }

            st.push(i);
        }

        return ans;
    }
};