class Solution {
public:
    int quickSelect(vector<int> &nums, int left, int right, int k) {
        if(left == right) return nums[left];

        int pivot_index = partition(nums, left, right);

        if(pivot_index == k) return nums[pivot_index];
        else if(pivot_index > k) return quickSelect(nums, left, pivot_index-1, k);
        else return quickSelect(nums, pivot_index+1, right, k);
    }

    int partition(vector<int> &nums, int left, int right) {
        int pivot = nums[right];
        int i = left;

        for(int j = left; j < right; j++) {
            if(nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }

        swap(nums[i], nums[right]);
        return i;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        return quickSelect(nums, 0, n-1, n-k);
    }
};