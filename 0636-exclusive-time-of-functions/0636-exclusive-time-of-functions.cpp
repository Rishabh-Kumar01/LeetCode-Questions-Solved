class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n,0);

        stack<int> st;

        int prevTime = 0;

        for(int i = 0; i < logs.size(); i++) {
            int firstColon = logs[i].find(':');
            int secondColon = logs[i].find(':', firstColon + 1);

            int id = stoi(logs[i].substr(0, firstColon));
            string type = logs[i].substr(firstColon + 1, secondColon - firstColon - 1);
            int timestamp = stoi(logs[i].substr(secondColon + 1));

            if(type == "start") {
                if(!st.empty()) {
                    int idx = st.top();
                    ans[idx] += (timestamp- prevTime);
                } 
                st.push(id);
                prevTime = timestamp;
            } else {
                if(!st.empty()) {
                    int idx = st.top();
                    st.pop();

                    ans[idx] += (timestamp- prevTime + 1);
                    prevTime = timestamp + 1;
                }
            }
        }

        return ans;
    }
};