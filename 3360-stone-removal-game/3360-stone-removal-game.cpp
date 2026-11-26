class Solution {
public:
    bool canAliceWin(int n) {
        bool alice = true;
        int s = 10;

        while (n - s >= 0) {
            n -= s--;
            alice = !alice;
        }

        return !alice;
    }
};