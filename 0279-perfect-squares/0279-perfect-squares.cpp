class Solution {
public:
    int numSquares(int n) {
        if(n == 0) return 0;

        int root = sqrt(n);
        if(root * root == n) return 1;

        queue<pair<int, int>> q;
        vector<bool> v(n+1, false);

        q.push({n, 0});
        v[n] = true;

        while(!q.empty()) {
            auto [current, steps] = q.front();
            q.pop();

            for(int i = 1; i * i <= current; i++) {
                int next = current - (i * i);

                if(next == 0) return steps + 1;

                if(!v[next]) {
                    v[next] = true;
                    q.push({next, steps+1});
                }
            }
        }

        return -1;
    }
};