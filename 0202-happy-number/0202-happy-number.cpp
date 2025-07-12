class Solution {
    long long customSum(long long n) {
        long long result=0;
        while (n) {
            result += (n%10) * (n%10);
            n=n/10;
        }
        return result;
    }
public:
    bool isHappy(int n) {
        unordered_map<long long, int> alreadyExists;
        long long N = n;
        while (alreadyExists[N]==0) {
            alreadyExists[N] = 1;
            N = customSum(N);
        }
        if (N==1) return true;
        return false;
    }
};