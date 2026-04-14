class Solution {
private:
    int n, m;
    long long f(int i, int j, vector<int> &robot, vector<vector<int>> &factory, vector<vector<long long>> &t) {
        if (i == n) {
            return 0;
        }
        if (j == m) {
            return 1e18;
        }

        if (t[i][j] != -1) {
            return t[i][j];
        }

        long long res = f(i, j+1, robot, factory, t);

        long long cost = 0;
        int pos = factory[j][0];
        int cap = factory[j][1];
        for (int k = 0; k < cap && i+k < n; k++) {
            cost += abs(robot[i+k] - pos);
            res = min(res, f(i+k+1, j+1, robot, factory, t) + cost);
        }

        return t[i][j] = res;
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        n = robot.size();
        m = factory.size();

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<vector<long long>> t(n, vector<long long>(m, -1));
        return f(0, 0, robot, factory, t);
    }
};