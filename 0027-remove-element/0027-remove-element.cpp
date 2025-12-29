class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start = 0;
        int n = nums.size();
        int end = n-1;

        while(start <= end) {

            if(nums[start] == val) {
                swap(nums[start], nums[end]);
                end--;
                continue;
            }

            start++;
        }

        return start;
    }
};