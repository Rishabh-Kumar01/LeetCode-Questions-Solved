class Solution {
public:
    void helper(string s, int idx, vector<string> &ans) {
        if(idx == s.size()) {
            ans.push_back(s);
            return;
        }     

        if(isdigit(s[idx])) {
            helper(s, idx+1, ans);
            return;
        }

        s[idx] = tolower(s[idx]);
        helper(s, idx+1, ans);

        s[idx] = toupper(s[idx]);
        helper(s, idx+1, ans);
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        helper(s, 0, ans);
        return ans;
    }
};