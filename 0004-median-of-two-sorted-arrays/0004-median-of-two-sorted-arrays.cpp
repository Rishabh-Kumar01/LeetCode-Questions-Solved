class Solution {
public:
    int helper(vector<int>& nums1, vector<int>& nums2, int m, int n, int idx1,
               int idx2, int k) {

        if (idx1 >= m) {
            return nums2[idx2 + k];
        }

        if (idx2 >= n) {
            return nums1[idx1 + k];
        }

        if (k == 0)
            return min(nums1[idx1], nums2[idx2]);

        if (nums1[idx1] <= nums2[idx2]) {
            return helper(nums1, nums2, m, n, idx1 + 1, idx2, k - 1);
        } else {
            return helper(nums1, nums2, m, n, idx1, idx2 + 1, k - 1);
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int total = m + n;

        int mid = total / 2;

        if (total % 2 == 1) {
            return helper(nums1, nums2, m, n, 0, 0, mid);
        } else {
            int mid1 = helper(nums1, nums2, m, n, 0, 0, mid);
            int mid2 = helper(nums1, nums2, m, n, 0, 0, mid - 1);
            return (mid1 + mid2) / 2.0;
        }
    }
};