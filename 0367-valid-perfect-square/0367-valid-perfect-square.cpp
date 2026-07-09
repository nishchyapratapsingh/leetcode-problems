class Solution {
public:
    bool isPerfectSquare(int num) {
        int r = sqrt(num);

        return 1LL* r * r == num;
    }
};