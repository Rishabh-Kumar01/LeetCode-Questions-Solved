class Solution {
public:
    int helper(int row, int col, vector<vector<char>>& board,
                vector<vector<bool>>& rowUsed, vector<vector<bool>>& colUsed,
                vector<vector<bool>>& boxUsed) {

        int emptyRow = -1;
        int emptyCol = -1;
        bool found = false;
        for (int i = 0; i < 9 && !found; i++) {

            for (int j = 0; j < 9 && !found; j++) {
                if (board[i][j] == '.') {
                    found = true;
                    emptyRow = i;
                    emptyCol = j;
                    break;
                }
            }

            
        }

        if (!found)
            return true;

        for (int i = 1; i <= 9; i++) {

            int boxIndex = (emptyRow / 3) * 3 + (emptyCol / 3);

            if (!rowUsed[emptyRow][i] && !colUsed[emptyCol][i] &&
                !boxUsed[boxIndex][i]) {

                board[emptyRow][emptyCol] = '0' + i;
                rowUsed[emptyRow][i] = true;
                colUsed[emptyCol][i] = true;
                boxUsed[boxIndex][i] = true;

                if(helper(emptyRow, emptyCol, board, rowUsed, colUsed, boxUsed)) return true;

                board[emptyRow][emptyCol] = '.';
                rowUsed[emptyRow][i] = false;
                colUsed[emptyCol][i] = false;
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

        helper(0, 0, board, rowUsed, colUsed, boxUsed);
    }
};