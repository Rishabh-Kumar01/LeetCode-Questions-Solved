class Solution {
public:
    vector<string> ans;
    
    void helper(string &half, string &curr, vector<bool> &used, string &mid) {
        if(curr.size() == half.size()) {
            string rev = curr;
            reverse(rev.begin(), rev.end());
            ans.push_back(curr + mid + rev);
            return;
        }
        
        for(int i = 0; i < half.size(); i++) {
            // Skip if already used
            if(used[i]) continue;
            
            // Skip duplicates: same as prev AND prev not used
            if(i > 0 && half[i] == half[i-1] && !used[i-1]) continue;
            
            used[i] = true;
            curr.push_back(half[i]);
            helper(half, curr, used, mid);
            curr.pop_back();
            used[i] = false;
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
        
        if(oddCount > 1) return {};
        
        // Step 3: Build half string
        string half = "";
        for(auto &[ch, count] : freq) {
            for(int i = 0; i < count / 2; i++) {
                half.push_back(ch);
            }
        }
        
        // Step 4: Sort for duplicate handling
        sort(half.begin(), half.end());
        
        // Step 5: Generate permutations
        string curr = "";
        vector<bool> used(half.size(), false);
        helper(half, curr, used, mid);
        
        return ans;
    }
};