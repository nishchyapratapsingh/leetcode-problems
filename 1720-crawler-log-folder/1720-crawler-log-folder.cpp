class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> s;
        for (auto log: logs) {
            if (log=="../" && !s.empty()) {
                s.pop();
            }
            else if (log!="./" && log!="../") {
                s.push(log);
            }
        }
        return s.size();
    }
};