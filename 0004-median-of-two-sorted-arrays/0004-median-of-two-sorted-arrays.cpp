class Solution {
public:
    int helper(vector<int>& nums1, vector<int>& nums2, int m, int n, int idx1,
               int idx2, int k) {

        if (idx1 >= m) {
            return nums2[idx2 + k - 1];
        }

        if (idx2 >= n) {
            return nums1[idx1 + k - 1];
        }

        if (k == 1)
            return min(nums1[idx1], nums2[idx2]);

        int half = k / 2;
        int mid1 = (idx1 + half - 1< nums1.size()) ? nums1[idx1 + half - 1] : INT_MAX;
        int mid2 = (idx2 + half - 1< nums2.size()) ? nums2[idx2 + half - 1] : INT_MAX;

        if (mid1 <= mid2) {
            // Eliminate first half of nums1
            return helper(nums1, nums2, m, n, idx1 + half, idx2, k - half);
        } else {
            // Eliminate first half of nums2
            return helper(nums1, nums2, m, n, idx1, idx2 + half, k - half);
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int total = m + n;

        int mid = total / 2;

        if (total % 2 == 1) {
            return helper(nums1, nums2, m, n, 0, 0, mid+1);
        } else {
            int mid1 = helper(nums1, nums2, m, n, 0, 0, mid);
            int mid2 = helper(nums1, nums2, m, n, 0, 0, mid + 1);
            cout<<"mid1 - "<<mid1<<endl;
            cout<<"mid 2 -"<<mid2<<endl;
            return (mid1 + mid2) / 2.0;
        }
    }
};