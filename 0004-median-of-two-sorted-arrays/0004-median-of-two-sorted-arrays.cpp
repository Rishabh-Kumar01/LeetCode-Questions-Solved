class Solution {
public:
    void helper(vector<int>& nums1, vector<int>& nums2, int m, int n, int idx1, int idx2, vector<int> &ans) {

        if(idx1 >= m) {
            for(int i = idx2; i < n; i++) {
                ans.push_back(nums2[i]);
            }
            return;
        }
        if(idx2 >= n) {
            for(int i = idx1; i < m; i++) {
                ans.push_back(nums1[i]);
            }
            return;
        }

        if(nums1[idx1] >= nums2[idx2]) {
            ans.push_back(nums2[idx2]);
            helper(nums1, nums2, m, n, idx1, idx2+1, ans);
        } else {
            ans.push_back(nums1[idx1]);
            helper(nums1, nums2, m, n, idx1+1, idx2, ans);
        }


    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int m = nums1.size();
        int n = nums2.size();
        int idx1 = 0;
        int idx2 = 0;

        helper(nums1, nums2, m, n, idx1, idx2, ans);

        int size = ans.size();

        if(size % 2 == 0) {
            int mid1 = ans[(size/2)-1];
            int mid2 = ans[((size/2))];
            return (double)(mid1 + mid2)/2.0;
        } 
        int mid = (size)/2;
        return (double)ans[mid];
    }
};