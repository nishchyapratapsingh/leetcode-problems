class Solution {
public:
    long long coloredCells(int n) {
        long long m=n;
        return m*m + (m-1) * (m-1);
    }
};