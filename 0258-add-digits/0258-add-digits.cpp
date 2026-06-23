class Solution {
public:
    int addDigits(int num) {
        if (num < 10) {
            return num;
        }

        int t = num;
        int sum = 0;
        while (t) {
            sum += t%10;
            t/=10;
        }
        return addDigits(sum);
    }
};