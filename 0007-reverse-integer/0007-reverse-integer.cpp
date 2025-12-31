class Solution {
public:
    int rev = 0;

    int reverse(int x) {
        if (x == 0) return rev;
        int digit = x % 10;
        if (rev > INT_MAX/10 || rev < INT_MIN/10) return 0;
        rev = rev * 10 + digit;
        return reverse(x / 10);
    }
};
