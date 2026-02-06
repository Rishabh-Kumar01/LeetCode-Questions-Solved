class Solution {
public:
    bool helper(vector<vector<char>>& board, int row, int col,
                vector<vector<bool>>& visited, int idx, const int& maxRow,
                const int& maxCol, const string& word) {

        if (idx >= word.size()) {
            return true;
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int newRow = dx[i] + row;
            int newCol = dy[i] + col;

            if (newRow >= 0 && newRow < maxRow && newCol >= 0 &&
                newCol < maxCol && !visited[newRow][newCol]) {

                if (board[newRow][newCol] == word[idx]) {
                    visited[newRow][newCol] = true;
                    
                    if(helper(board, newRow, newCol, visited, idx + 1, maxRow,
                           maxCol, word)) return true;
                    
                    visited[newRow][newCol] = false;
                }
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == word[0]) {
                    int idx = 1;
                    visited[i][j] = true;

                    if (helper(board, i, j, visited, idx, m, n, word))
                        return true;
                    
                    visited[i][j] = false;
                }
            }
        }

        return false;
    }
};