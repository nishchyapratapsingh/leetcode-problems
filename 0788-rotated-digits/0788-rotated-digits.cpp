class Solution {
private:
    bool f(int num) {
        int d;
        bool diff = 0;
        while (num) {
            d = num%10;
            num/=10;
            if (d == 0 || d == 1 || d == 8) {
            }
            else if (d == 2 || d == 5 || d == 6 || d == 9) {
                diff = 1;
            }
            else return false;  
        }

        return diff;
    }
public:
    int rotatedDigits(int n) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (f(i)) {
                cnt++;
            }
        }

        return cnt;
    }
};