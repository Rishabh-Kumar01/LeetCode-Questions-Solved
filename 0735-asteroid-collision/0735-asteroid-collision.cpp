class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();

        for(int i = 0; i < n; i++) {
            int currEle = asteroids[i];
            if(currEle > 0) st.push(currEle);
            else {
                bool alive = true;

                while(!st.empty() && st.top() > 0 && alive) {
                    int stTop = st.top();

                    if(stTop > abs(currEle)) alive = false;
                    else if(stTop < abs(currEle)) {
                        st.pop();
                    } else {
                        st.pop();
                        alive = false;
                    }
                }

                if(alive) st.push(currEle);
            }
        }

        vector<int> ans(st.size());

        for(int i = ans.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
    
        return ans;
    }
};