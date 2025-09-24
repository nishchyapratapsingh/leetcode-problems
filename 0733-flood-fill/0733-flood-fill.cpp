class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};
        queue<pair<int, int>> q;
        int startcolor = image[sr][sc];
        if (startcolor == color) return image;

        image[sr][sc]=color;
        
        q.push({sr, sc});
        while (!q.empty()) {
            auto [r, c]=q.front();
            q.pop();
            for (int i=0; i<4; i++) {
                int irow = r+drow[i];
                int icol = c+dcol[i];

                if (irow>=0 && irow<image.size() && icol>=0 && icol<image[0].size() && image[irow][icol]==startcolor)
                {image[irow][icol]=color;
                q.push({irow, icol}); }
            }
        }
        return image;
    }
};