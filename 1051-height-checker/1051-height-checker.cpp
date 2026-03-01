class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sorted = heights;
        sort(sorted.begin(), sorted.end());
        int n = heights.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (heights[i] != sorted[i]) {
                cnt++;
            }
        }

        return cnt;
    }
};