class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int cnt = 0;

        int s = 0;
        int e = 1;

        set<pair<int,int>> st;

        while(e < n) {
        
            if(s == e) {
                e++;
                if(e >= n) break;
            }

            int diff = nums[e] - nums[s];

            if(diff == k && st.find({nums[e], nums[s]}) == st.end()) {
                cout<<"Inside if conidition :"<<s<<" , "<<e<<" , "<<diff<<" , "<<nums[e]<<" , "<<nums[s]<<endl;;
                st.insert({nums[e], nums[s]});
                cnt += 1;
                e++;
                
            } else if(diff > k) s++;
            else e++;

        }

        return cnt;
    }
};