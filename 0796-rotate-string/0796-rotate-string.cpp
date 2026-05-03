class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        if (goal.length() != n) return false;

        for (int i = 0; i < n; i++) {
            if (s[i] == goal[0]) {
                if (s.substr(i, n-i) == goal.substr(0, n-i)) {
                    if (s.substr(0, i) == goal.substr(n-i, i)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};