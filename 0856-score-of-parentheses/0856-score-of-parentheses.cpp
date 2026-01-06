class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int n = s.size();

        st.push(0);

        for(auto c : s) {

            if(c == '(') st.push(0);
            else {
                int currScore = st.top();
                st.pop();

                int score;
                if(currScore == 0) score = 1;
                else score = 2 * currScore;

                st.top() += score;
            }
        }

        return st.top();
    }
};