class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;
        int n = points.size();
        int prevx, prevy;

        for (int i = 0; i < n; i++) {
            int x = points[i][0];
            int y = points[i][1];
            if (i!=0) {
                int t = min(abs(x - prevx), abs(y - prevy));
                int t1 = max(abs(x - prevx), abs(y - prevy));
                time += t;
                time += t1 - t;
            }

            prevx = x;
            prevy = y;
        }

        return time;
    }
};