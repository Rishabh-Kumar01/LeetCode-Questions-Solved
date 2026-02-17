class Solution {
public:
    int helper(int idx, vector<pair<int, int>> emptyCells,
               vector<vector<char>>& board, vector<vector<bool>>& rowUsed,
               vector<vector<bool>>& colUsed, vector<vector<bool>>& boxUsed) {

        if (idx == emptyCells.size())
            return true; // All filled!

        auto [row, col] = emptyCells[idx];

        for (int i = 1; i <= 9; i++) {

            int boxIndex = (row / 3) * 3 + (col / 3);

            if (!rowUsed[row][i] && !colUsed[col][i] &&
                !boxUsed[boxIndex][i]) {

                board[row][col] = '0' + i;
                rowUsed[row][i] = true;
                colUsed[col][i] = true;
                boxUsed[boxIndex][i] = true;

                if (helper(idx + 1, emptyCells, board,
                           rowUsed, colUsed, boxUsed))
                    return true;

                board[row][col] = '.';
                rowUsed[row][i] = false;
                colUsed[col][i] = false;
                boxUsed[boxIndex][i] = false;
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> colUsed(9, vector<bool>(10, false));
        vector<vector<bool>> rowUsed(9, vector<bool>(10, false));
        vector<vector<bool>> boxUsed(9, vector<bool>(10, false));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int digit = board[i][j] - '0';
                    int boxIndex = (i / 3) * 3 + (j / 3);
                    rowUsed[i][digit] = true;
                    colUsed[j][digit] = true;
                    boxUsed[boxIndex][digit] = true;
                }
            }
        }

        vector<pair<int, int>> emptyCells;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    emptyCells.push_back({i, j});
                }
            }
        }

        helper(0, emptyCells, board, rowUsed, colUsed, boxUsed);
    }
};