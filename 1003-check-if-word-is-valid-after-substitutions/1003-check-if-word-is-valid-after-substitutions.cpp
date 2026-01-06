class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto ch : s) {
            if(ch == 'c' && st.size() >= 2) {
                char second = st.top();
                st.pop();

                char first = st.top();

                if(first == 'a' && second == 'b') {
                    st.pop();
                } else {
                    st.push(second);
                    st.push(ch);
                }

            } else st.push(ch);
        }

        return st.empty();
    }
};