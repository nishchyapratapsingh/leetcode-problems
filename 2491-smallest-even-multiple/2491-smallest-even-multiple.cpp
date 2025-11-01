class Solution {
public:
    int smallestEvenMultiple(int n) {
        if (n%2==0) return n;
        for (int i=2*n;; i+=n) {
            if (i%2==0) return i;
        }
        return 0;
    }
};