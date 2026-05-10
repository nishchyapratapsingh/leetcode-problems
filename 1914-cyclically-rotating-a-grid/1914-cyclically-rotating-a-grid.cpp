class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        for (int l = 0; l < min(m, n)/2; ++l) {
            vector<int> layer;
            //first row
            for (int j = l; j < n-l; j++) {
                layer.push_back(grid[l][j]);
            }
            //last col
            for (int i = l+1; i < m-l; i++) {
                layer.push_back(grid[i][n-l-1]);
            }
             //last row
            for (int j = n-l-2; j >= l; j--) {
                layer.push_back(grid[m-l-1][j]);
            }
            //first col
            for (int i = m-l-2; i >= l+1; i--) {
                layer.push_back(grid[i][l]);
            }  

            int len = layer.size();
            int rot = k % len;

            rotate(layer.begin(), layer.begin() + rot, layer.end());

            int idx = 0;

            // top
            for (int j = l; j < n - l; ++j)
                grid[l][j] = layer[idx++];

            // right
            for (int i = l + 1; i < m - l - 1; ++i)
                grid[i][n - l - 1] = layer[idx++];

            // bottom
            for (int j = n - l - 1; j >= l; --j)
                grid[m - l - 1][j] = layer[idx++];

            // left
            for (int i = m - l - 2; i > l; --i)
                grid[i][l] = layer[idx++];
        }

        return grid;
    } 
};

/*
grid (m*n) both even
k 


jth layer =  jth row, n-jth row, jth col , n-jth col

*/