class Solution {
public:
    vector<string> ans;
    
    void helper(string &curr, unordered_map<char, int> &halfFreq, int halfLen, string &mid) {
        // Base case: half is complete
        if(curr.size() == halfLen) {
            string rev = curr;
            reverse(rev.begin(), rev.end());
            ans.push_back(curr + mid + rev);
            return;
        }
        
        // Try each character that has remaining count
        for(auto &[ch, count] : halfFreq) {
            if(count > 0) {
                count--;                // use it
                curr.push_back(ch);
                helper(curr, halfFreq, halfLen, mid);
                curr.pop_back();        // backtrack
                count++;                // restore
            }
        }
    }
    
    vector<string> generatePalindromes(string s) {
        // Step 1: Count frequencies
        unordered_map<char, int> freq;
        for(char ch : s) {
            freq[ch]++;
        }
        
        // Step 2: Check validity & find middle char
        string mid = "";
        int oddCount = 0;
        
        for(auto &[ch, count] : freq) {
            if(count % 2 == 1) {
                oddCount++;
                mid = ch;
            }
        }
        
        // More than one odd count → impossible
        if(oddCount > 1) return {};
        
        // Step 3: Build half frequency map
        unordered_map<char, int> halfFreq;
        int halfLen = 0;
        
        for(auto &[ch, count] : freq) {
            if(count / 2 > 0) {
                halfFreq[ch] = count / 2;
                halfLen += count / 2;
            }
        }
        
        // Step 4: Generate permutations
        string curr = "";
        helper(curr, halfFreq, halfLen, mid);
        
        return ans;
    }
};