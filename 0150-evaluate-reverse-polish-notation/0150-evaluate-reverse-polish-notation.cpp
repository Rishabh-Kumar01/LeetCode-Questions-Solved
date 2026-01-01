class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto token: tokens) {
            if(token.length() == 1 && (token == "+" || token == "-" || token == "*" || token == "/" )) {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();

                int cal;
                if (token == "+") {
                    cal = second + first;
                } else if (token == "-") {
                    cal = second - first;
                } else if (token == "*") {
                    cal = second * first;
                } else {
                    cal = second / first;
                }
                st.push(cal);
            } else st.push(stoi(token));
        }

        return st.top();
    }
};