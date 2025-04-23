class Solution {
public:

    void revInPlace(vector<char> &s, int i, int j) {
        if (i>j) {
            return;
        }

        swap(s[i], s[j]);
        revInPlace(s, i+1, j-1);
    }

    void reverseString(vector<char>& s) {
        revInPlace(s, 0, s.size()-1);
    }
};