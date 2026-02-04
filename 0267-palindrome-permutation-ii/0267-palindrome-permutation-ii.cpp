class Solution {
public:
    vector<string> ans;

    void helper(string &curr, const int &halfLen, unordered_map<char, int> &halfFreq, const string &mid) {

        if(curr.size() == halfLen) {
            string rev = curr;
            reverse(rev.begin(), rev.end());
            ans.push_back(curr + mid + rev);
            return;
        }

        for(auto &[ch, count]: halfFreq) {
            if(count > 0) {
                count--;
                curr.push_back(ch);
                helper(curr, halfLen, halfFreq, mid);
                curr.pop_back();
                count++;
            }
        }

    }

    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> mpp;

        for(auto c: s) mpp[c]++;

        int cntOdd = 0;
        string mid = "";

        for(auto &[ch, count] : mpp) {
            if(count % 2 == 1) {
                mid = ch;
                cntOdd++;
            }
        }

        if(cntOdd > 1) return {};


        int halfLen = 0;
        unordered_map<char, int> halfFreq;

        for(auto &[ch, count] : mpp) {
            if(count / 2 > 0) {
                halfFreq[ch] = count/2;
                halfLen += count/2;
            }
        }

        string curr = "";
        helper(curr, halfLen, halfFreq, mid);

        return ans;
    }
};