class Solution {
public:
    void helper(vector<vector<string>> &ans, vector<string> &curr, int idx, const string &s){

        if(idx >= s.size()) {
            ans.push_back(curr);
            return;
        }

        for(int i = idx; i < s.size(); i++) {

            if(isPalindrome(s, idx, i)) {
                string temp = s.substr(idx, i - idx + 1);
                curr.push_back(temp);
                helper(ans, curr, i+1, s);
                curr.pop_back();
            }
        }

    }

    bool isPalindrome(const string &s, int start, int end) {

        while(start <= end) {
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }

        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;

        helper(ans, curr, 0, s);

        return ans;
    }
};