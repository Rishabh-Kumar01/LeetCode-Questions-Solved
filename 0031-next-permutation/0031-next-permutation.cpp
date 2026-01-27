class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int pivot = -1;

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            int mini = INT_MAX;

            for (int i = n - 1; i > pivot; i--) {
                if (nums[i] > nums[pivot]) {
                    mini = i;
                    break;
                }
            }

            swap(nums[pivot], nums[mini]);
            reverse(nums.begin() + pivot + 1, nums.end());
        }
    }
};