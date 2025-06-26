class Solution {
private:
    double fastPow(double x, long long n) {
        if (n==0) {
            return 1.0;
        }
        
        double half = fastPow(x, n/2);

        if (n%2==0) {
            return half*half;
        }
        else {
            return x*half*half;
        }

    }

public:
    double myPow(double x, int n) {
        long long nn = n;
        if (n<0) {
            nn = -nn;
            x = 1/x;
        }
        double res = fastPow(x, nn);
        return res;
    }
};