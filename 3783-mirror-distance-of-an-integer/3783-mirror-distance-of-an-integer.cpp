class Solution {
private:
    int reverseInt(int n) {
        string str = to_string(n);
        reverse(str.begin(), str.end());
        return stoi(str);
    }
public:
    int mirrorDistance(int n) {
        return abs(n-reverseInt(n));
    }
};