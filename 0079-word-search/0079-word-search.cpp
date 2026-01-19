class Solution {
    bool backtrack(vector<vector<char>>& board, string &word, int n, int m, int i, int j, int idx) {
        if (idx == word.length()) {
            return true;
        }
        
        if (i < 0 || j < 0 || i >= n|| j >= m || board[i][j] != word[idx] ) return false;

        char temp = board[i][j];
        board[i][j] = '#';

        bool found = backtrack(board, word, n, m, i+1, j, idx+1) || 
                    backtrack(board, word, n, m, i, j+1, idx+1) || 
                    backtrack(board, word, n, m, i-1, j, idx+1) || 
                    backtrack(board, word, n, m, i, j-1, idx+1);
        
        board[i][j] = temp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (backtrack(board, word, n, m, i, j, 0)) return true;
            }
        }
        return false;
    }
};