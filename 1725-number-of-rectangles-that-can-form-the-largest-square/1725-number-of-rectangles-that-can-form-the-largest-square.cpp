class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxLen = 0;
        int cnt = 0;

        for (auto &rec : rectangles) {
            maxLen = max(min(rec[0], rec[1]), maxLen);
        }

        for (auto &rec : rectangles) {
            if (maxLen == min(rec[0], rec[1])) cnt++;
        }

        return cnt;
    }
};