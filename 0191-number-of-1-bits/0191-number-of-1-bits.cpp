class Solution {
public:
    int hammingWeight(int n) {
        int t = n;

        int ans = 0;
        while (t) {
            if (t % 2 == 1) {
                ans++;
            }

            t/=2;
        }

        return ans;
    }
};