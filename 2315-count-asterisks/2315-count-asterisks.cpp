class Solution {
public:
    int countAsterisks(string s) {
        bool isPair = false;
        int cnt = 0;

        for (char c : s) {
            if (!isPair && c == '*') {
                cnt++;
            }
            if (c == '|') {
                isPair = !isPair;
            }
        }

        return cnt;
    }
};