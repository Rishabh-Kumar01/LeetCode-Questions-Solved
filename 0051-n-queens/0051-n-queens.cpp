class Solution {
public:
    void helper(int row, int n, vector<bool>& colUsed, vector<bool>& diag1,
                vector<bool>& diag2, vector<string>& board,
                vector<vector<string>>& result) {

        // Base case
        if (row == n) {
            result.push_back(board); // Found a solution!
            return;
        }

        // Try each column in this row
        for (int col = 0; col < n; col++) {

            int d1 = row - col + (n - 1); // Diagonal 1 index
            int d2 = row + col;           // Diagonal 2 index

            // Check if this column is safe
            if (colUsed[col] || diag1[d1] || diag2[d2]) {
                continue; // Not safe, try next column
            }

            // Place queen
            board[row][col] = 'Q';
            colUsed[col] = true;
            diag1[d1] = true;
            diag2[d2] = true;

            // Recurse to NEXT ROW (not next column!)
            helper(row + 1, n, colUsed, diag1, diag2, board, result);

            // Backtrack
            board[row][col] = '.';
            colUsed[col] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> colUsed(n, false);
        vector<bool> diag1(2 * n - 1, false);    // Track \ diagonals
        vector<bool> diag2(2 * n - 1, false);    // Track / diagonals
        vector<vector<string>> ans;           // Store all solutions
        vector<string> board(n, string(n, '.')); // Current board state

        helper(0, n, colUsed, diag1, diag2, board, ans);

        return ans;
    }
};