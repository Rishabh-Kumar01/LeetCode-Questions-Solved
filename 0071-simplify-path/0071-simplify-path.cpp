class Solution {
public:
    string simplifyPath(string path) {
        vector<string> temp;
        stringstream ss(path);
        string token;

        while(getline(ss, token, '/')) {
            temp.push_back(token);
        }
        
        int n = temp.size();

        stack<string> st;

        for(int i = 0; i < n; i++) {
            if(temp[i] == "" || temp[i] == ".") continue;
            else if(temp[i] == "..") {
                if(!st.empty()) st.pop();
            }
            else st.push(temp[i]);
        }

        string ans = "";

        while(!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        return ans.empty() ? "/" : ans;
    }
};