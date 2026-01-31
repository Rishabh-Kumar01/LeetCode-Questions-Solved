class Solution {
public:
    void helper(string &curr, vector<string> &ans, int n, int cntOpen, int cntClose){
        
        if(cntOpen > n) return;

        if(cntOpen == n && cntClose == n) {
            ans.push_back(curr);
            return;
        }

        if(cntOpen <= n) {
            curr.push_back('(');
            helper(curr, ans, n, cntOpen+1, cntClose);
            curr.pop_back();
        }

        if(cntClose < cntOpen) {
            curr.push_back(')');
            helper(curr, ans, n, cntOpen, cntClose+1);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";

        helper(curr, ans, n, 0, 0);

        return ans;
    }
};