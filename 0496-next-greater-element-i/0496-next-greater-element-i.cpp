class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> m;

        int n1 = nums1.size();
        int n2 = nums2.size();

        for(int i = 0; i < n2; i++) {

            while(!st.empty() && nums2[i] > nums2[st.top()]) {
                m[nums2[st.top()]] = nums2[i];
                st.pop();
            }

            st.push(i);
        }

        vector<int> ans(n1, -1);

        for(int i = 0; i < n1; i++) {
            if(m.count(nums1[i])) {
                ans[i] = m[nums1[i]];
            }
        }

        return ans;
    }
};