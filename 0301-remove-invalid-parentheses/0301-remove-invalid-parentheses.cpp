class Solution {
public:
    bool isValid(string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') count--;
            if (count < 0) return false;
        }
        return count == 0;
    }

    void helper(string s, int index, int openRem, int closeRem, 
                vector<string>& result) {
        
        // Base case: no more removals needed
        if (openRem == 0 && closeRem == 0) {
            if (isValid(s)) {
                result.push_back(s);
            }
            return;
        }

        for (int i = index; i < s.length(); i++) {
            
            // Skip duplicates
            if (i > index && s[i] == s[i-1]) continue;
            
            // Only remove parentheses, not letters
            if (s[i] == '(' || s[i] == ')') {
                
                string newStr = s.substr(0, i) + s.substr(i + 1);
                
                // Remove '(' if we still need to remove open
                if (s[i] == '(' && openRem > 0) {
                    helper(newStr, i, openRem - 1, closeRem, result);
                }
                
                // Remove ')' if we still need to remove close
                else if (s[i] == ')' && closeRem > 0) {
                    helper(newStr, i, openRem, closeRem - 1, result);
                }
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        
        // Calculate minimum removals
        int misplacedOpen = 0, misplacedClose = 0;
        
        for (char c : s) {
            if (c == '(') {
                misplacedOpen++;
            } else if (c == ')') {
                if (misplacedOpen > 0) {
                    misplacedOpen--;   // Matched!
                } else {
                    misplacedClose++;  // Unmatched ')'
                }
            }
        }
        
        vector<string> result;
        helper(s, 0, misplacedOpen, misplacedClose, result);
        return result;
    }
};
