class Solution {
public:
    void helper(int row, int n, vector<bool>& colUsed, vector<bool>& diag1,
                vector<bool>& diag2, vector<vector<string>>& ans,
                vector<string>& board) {

        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            int d1 = row - col + (n - 1);
            int d2 = row + col;

            if (colUsed[col] || diag1[d1] || diag2[d2]) {
                continue;
            }

            board[row][col] = 'Q';
            colUsed[col] = true;
            diag1[d1] = true;
            diag2[d2] = true;

            // Recurse to NEXT ROW (not next column!)
            helper(row + 1, n, colUsed, diag1, diag2, ans, board);

            // Backtrack
            board[row][col] = '.';
            colUsed[col] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }
    int totalNQueens(int n) {
        vector<bool> colUsed(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        helper(0, n, colUsed, diag1, diag2, ans, board);

        return ans.size();
    }
};