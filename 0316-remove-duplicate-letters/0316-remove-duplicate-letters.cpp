class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> mpp;

        int n = s.size();

        for(int i = 0; i < n; i++) mpp[s[i]] = i;

        unordered_set<char> inStack;
        stack<char> st;

        for(int i = 0; i < n; i++) {
            if(inStack.count(s[i])) continue;
            else {
                while(!st.empty() && st.top() > s[i]) {
                    if(mpp[st.top()] > i) {
                        inStack.erase(st.top());
                        st.pop();
                    } else break;
                }

                st.push(s[i]);
                inStack.insert(s[i]);
            }
        }

        string ans(st.size(), 'a');

        for(int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};