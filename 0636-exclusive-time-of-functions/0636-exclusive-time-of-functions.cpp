class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n,0);

        stack<int> st;

        int prevTime = 0;

        for(int i = 0; i < logs.size(); i++) {
            stringstream ss(logs[i]);
            vector<string> temp;
            string itr;

            while(getline(ss, itr, ':')) {
                temp.push_back(itr);
            }

            if(temp[1] == "start") {
                if(!st.empty()) {
                    int idx = st.top();
                    ans[idx] += (stoi(temp[2]) - prevTime);
                } 
                st.push(stoi(temp[0]));
                prevTime = stoi(temp[2]);
            } else {
                if(!st.empty()) {
                    int idx = st.top();
                    st.pop();

                    ans[idx] += (stoi(temp[2]) - prevTime + 1);
                    prevTime = stoi(temp[2]) + 1;
                }
            }
        }

        return ans;
    }
};