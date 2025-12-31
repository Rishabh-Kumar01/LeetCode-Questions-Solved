class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;

        int n = nums.size();

        for(int i = 0; i < n; i++) {

            int s = i+1;
            int e = n-1;

            long long int target = -((long long int)nums[i]);

            while(s < e) {
                long long int sum = (long long int)(nums[s] + nums[e]);

                if(sum == target) {
                    ans.push_back({nums[i], nums[s], nums[e]});
                    s++;
                    e--;

                    while(s < e && nums[s] == nums[s-1]) s++;
                    while(s < e && nums[e] == nums[e+1]) e--;
                } else if(sum > target) e--;
                else s++;
            }

            while(i < n-1 && nums[i] == nums[i+1]) i++;
        }

        return ans;
    }
};