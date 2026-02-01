class Solution {
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c) {
                return false;
            }
        }

        for (int j = 0; j < 9; j++) {
            if (board[row][j] == c) {
                return false;
            }
        }

        int boxRow = (row/3)*3;
        int boxCol = (col/3)*3;

        for (int i = boxRow; i < boxRow+3; i++) {
            for (int j = boxCol; j < boxCol+3; j++) {
                if (board[i][j] == c) {
                    return false;
                }
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board, int pos) {
        if (pos == 81) {
            return true;
        }

        int row = pos/9;
        int col = pos%9;

        if (board[row][col] != '.') {
            return solve(board, pos+1);
        }

        for (char c = '1'; c <= '9'; c++) {
            if (isValid(board, row, col, c)) {
                board[row][col] = c;
                if (solve(board, pos+1)) return true;
                board[row][col] = '.';
            }
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0);
    }
};