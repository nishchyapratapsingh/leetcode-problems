class Solution {
public:
    int climbStairs(int n) {
        if (n==2) {
            return 2;
        } else if (n==1) {
            return 1;
        } else if (n==0) {
            return 0;
        }

        int prev1 = 2;
        int prev2 = 1;
        int current = 0;

        for (int i=3; i<=n; i++) {
            current = prev1+prev2;
            prev2 = prev1;
            prev1 = current;
        }

        return current;
    }
};