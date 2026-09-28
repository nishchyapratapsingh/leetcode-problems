class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1;
        int len = 0;

        for (char c : s) {
            int w = widths[c - 'a'];

            if (len + w > 100) {
                lines++;
                len = w;
            } else {
                len += w;
            }
        }

        return {lines, len};
    }
};