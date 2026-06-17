class Solution {
public:
    string removeTrailingZeros(string num) {
        int n = num.length();
        for (int j = n-1; j >= 0; j--) {
            if (num[j] == '0') {
                num.pop_back();
            }
            else return num;
        }

        return num;
    }
};