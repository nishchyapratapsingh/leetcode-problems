class Solution {
private:
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};
    void dfs(int r, int c, vector<vector<bool>> &visited, vector<vector<char>> &board) {
        visited[r][c] = 1;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nc >= 0 && nr < board.size() && nc < board[0].size() && board[nr][nc] == 'O' && !visited[nr][nc]) {
                dfs(nr, nc, visited, board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O') {
                dfs(0, i, visited, board);
            }
        }

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                dfs(i, 0, visited, board);
            }
        }

        for (int i = 0; i < m; i++) {
            if (board[n-1][i] == 'O') {
                dfs(n-1, i, visited, board);
            }
        }

        for (int i = 0; i < n; i++) {
            if (board[i][m-1] == 'O') {
                dfs(i, m-1, visited, board);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};