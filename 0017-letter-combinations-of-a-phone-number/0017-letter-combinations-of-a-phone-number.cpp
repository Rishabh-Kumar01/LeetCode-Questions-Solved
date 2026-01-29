class Solution {
public:
    void helper(string input, int idx, vector<string> &ans, string &curr, unordered_map<char, string> &mpp, int n) {

        if(curr.size() == n) {
            ans.push_back(curr);
            return;
        }

        char temp = input[idx];
        string alph = mpp[temp];
        for(int i = 0; i < alph.size(); i++) {
            curr += alph[i];

            helper(input, idx+1, ans, curr, mpp, n);

            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mpp;

        mpp.insert({'2', "abc"});
        mpp.insert({'3', "def"});
        mpp.insert({'4', "ghi"});
        mpp.insert({'5', "jkl"});
        mpp.insert({'6', "mno"});
        mpp.insert({'7', "pqrs"});
        mpp.insert({'8', "tuv"});
        mpp.insert({'9', "wxyz"});

        vector<string> ans;
        string curr = "";

        helper(digits, 0, ans, curr, mpp, digits.size());

        return ans;
    }
};