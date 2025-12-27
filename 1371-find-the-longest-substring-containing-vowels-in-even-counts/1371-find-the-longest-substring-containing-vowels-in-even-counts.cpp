class Solution {
public:
    int findTheLongestSubstring(string s) {
        string vowels = "aieou";

        unordered_map<int, int> m;
        int state = 0;
        m[state] = -1;

        int ans = 0;

        for(int i = 0; i < s.size(); i++ ) {
            int pos = vowels.find(s[i]);

            if(pos != string::npos) {
                state = state ^ (1 << pos);
            }

            if(m.count(state)) {
                ans = max(ans, i - m[state]);
            } else {
                m[state] = i;
            }

        }

        return ans;
    }
};