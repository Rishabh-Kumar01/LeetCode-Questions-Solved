class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<pair<int, int>, int>> q;

        int m = rooms.size();
        int n = rooms[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(rooms[i][j] == 0) q.push({{i, j}, 0});
            }
        }

        while(!q.empty()) {
            auto [cord, dist] = q.front();
            q.pop();
            int row = cord.first;
            int col = cord.second;

            int right = rooms[row][min(col+1, n-1)];
            int bottom = rooms[min(row+1, m-1)][col];
            int left = rooms[row][max(0, col - 1)];
            int top = rooms[max(0, row - 1)][col];

            if(right == INT_MAX) {
                rooms[row][min(col+1, n-1)] = dist + 1;
                q.push({{row, min(col+1, n-1)}, dist + 1});
            }

            if(bottom == INT_MAX) {
                rooms[min(row+1, m-1)][col] = dist + 1;
                q.push({{min(row+1, m-1), col}, dist + 1});
            }

            if(left == INT_MAX) {
                rooms[row][max(0, col - 1)] = dist + 1;
                q.push({{row, max(0, col - 1)}, dist + 1});
            }

            if(top == INT_MAX) {
                rooms[max(0, row - 1)][col] = dist + 1;
                q.push({{max(0, row - 1), col}, dist + 1});
            }
        }
    }
}; 