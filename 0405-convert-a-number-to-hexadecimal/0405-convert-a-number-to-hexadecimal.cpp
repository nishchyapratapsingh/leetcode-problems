class Solution {
public:
    string toHex(int num) {
        unsigned int n = num;

        if (n == 0) {
            return "0";
        }

        string ans;

        char hex[] = "0123456789abcdef";

        while (n) {
            int rem = n % 16;

            ans += hex[rem];

            n/=16;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};