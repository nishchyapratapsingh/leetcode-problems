class Solution {
    long long modExp(long long base, long long exp, int MOD) {
        long long result=1;
        base%=MOD;
        while(exp>0) {
            if (exp%2==1) {
                result=(result*base)%MOD;
            }
            base=(base*base)%MOD;
            exp/=2;
        }
        return result;
    }
public:
    int countGoodNumbers(long long n) {
        const int MOD = 1000000007;
        long long evenCount = (n+1)/2;
        long long oddCount = (n/2);
        long long part1 = modExp(5, evenCount, MOD);
        long long part2 = modExp(4, oddCount, MOD);
        return (part1*part2)%MOD;
    }
};