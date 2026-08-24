class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt = 0;

        while (x && y) {
            if (x % 2 != y % 2) cnt++;

            x/=2;
            y/=2;
        }

        while (x) {
            if (x % 2) cnt++;
            x/=2;
        }

        while (y) {
            if (y % 2) cnt++;
            y/=2;
        }

        return cnt;
    }
};