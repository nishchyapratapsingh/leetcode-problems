class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int ogColor = image[sr][sc];
        if (ogColor == color) {
            return image;
        }

        queue<pair<int, int>> q;
        q.emplace(sr, sc);
        image[sr][sc] = color;

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        while (!q.empty()) {
            auto[row, col] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr < n && nr >= 0 
                && nc < m && nc >= 0 
                && image[nr][nc] == ogColor) {
                    q.emplace(nr, nc);
                    image[nr][nc] = color;
                }
            }
        }

        return image;
    }
};