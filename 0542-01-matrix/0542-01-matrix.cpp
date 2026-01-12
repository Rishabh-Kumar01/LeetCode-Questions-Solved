class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans(m, vector<int> (n, -1));

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {

                int newRow = row + dx[i];
                int newCol = col + dy[i];

                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && ans[newRow][newCol] == -1) {
                    ans[newRow][newCol] = ans[row][col] + 1;
                    q.push({newRow, newCol});
                }
            }
        }

        return ans;
    }
};