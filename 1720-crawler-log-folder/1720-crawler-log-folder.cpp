class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<int> s;
        for (auto log: logs) {
            if (log=="../" && !s.empty()) {
                s.pop();
            }
            else if (log!="./" && log!="../") {
                s.push(1);
            }
        }
        return s.size();
    }
};