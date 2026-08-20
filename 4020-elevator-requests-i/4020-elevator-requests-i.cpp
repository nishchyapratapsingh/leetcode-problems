class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int cur = 0;
        int time = 0;

        for (int req : requests) {
            time += abs(req - cur);
            cur = req;
        }

        return time;
    }
};