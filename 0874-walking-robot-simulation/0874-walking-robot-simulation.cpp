class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obs;

        for (int i = 0; i < obstacles.size(); i++) {
            string key = to_string(obstacles[i][0]) + ',' + to_string(obstacles[i][1]);
            obs.insert(key);
        }

        vector<pair<int, int>> dirs = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };

        int dir = 0;
        int x = 0, y = 0;
        int mx = 0;

        for (int cmd: commands) {
            if (cmd == -2) {
                dir = (dir + 3)%4;
            }
            else if (cmd == -1) {
                dir = (dir + 1)%4;
            }

            else {
                for (int i = 0; i < cmd; i++) {
                    int nx = x + dirs[dir].first;
                    int ny = y + dirs[dir].second;

                    string key = to_string(nx) + ',' + to_string(ny);

                    if (obs.count(key)) {
                        break;
                    }

                    x = nx;
                    y = ny;

                    mx = max(mx, nx*nx + ny*ny);
                }
            }
        }

        return mx;
    }
};