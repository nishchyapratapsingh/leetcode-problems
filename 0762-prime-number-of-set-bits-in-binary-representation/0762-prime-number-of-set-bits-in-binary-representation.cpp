class Solution {
    bool isPrime(int num) {
        return (num == 2 || num == 3 || num == 5 || num == 7 || num == 11 || num == 13 || num == 17 || num == 19);
    }
public:
    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        for (int i = left; i <= right; i++) {
            int t = i;
            int setBits = 0;
            while (t) {
                if (t%2 == 1) {
                    setBits++;
                }
                t/=2;
            }

            if (isPrime(setBits)) {
                cnt++;
            }
        }

        return cnt;
    }
};