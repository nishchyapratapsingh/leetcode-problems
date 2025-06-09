class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pattern(numRows);
        for (int i=0; i<numRows; i++) {
            pattern[i].resize(i+1);
            pattern[i][0] = pattern[i][i] = 1;
            for (int j=1; j<i; j++) {
                pattern[i][j] = pattern[i-1][j-1] + pattern[i-1][j];
            }
        }
        return pattern;
    }
};