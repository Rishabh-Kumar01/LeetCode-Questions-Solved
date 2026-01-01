class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> m;
        m.insert({')', '('});
        m.insert({'}', '{'});
        m.insert({']', '['});

        stack<char> st;

        for(auto c: s) {
            if(c == '(' || c == '{' || c == '[') st.push(c);
            else {
                if(!st.empty()) {
                    char temp = st.top();
                    st.pop();
                    if(m[c] != temp) return false;
                } else return false;
            }
        }

        if(st.empty()) return true;

        return false;
    }
};