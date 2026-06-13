class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        string ans;

        int i = 0, j = 0;
        int n = num1.size(), m = num2.size();

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());


        while (i < n && j < m) {
            int sum = (num1[i] - '0') + (num2[j] - '0') + carry;
            carry = sum/10;
            ans += (sum % 10 + '0');

            i++;
            j++;
        }

        while (i < n) {
            int sum = (num1[i] - '0') + carry;
            carry = sum/10;
            ans += (sum % 10 + '0');
            i++;
        }

        while (j < m) {
            int sum = (num2[j] - '0') + carry;
            carry = sum/10;
            ans += (sum % 10 + '0');
            j++;
        }

        if (carry) {
            ans += to_string(carry);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};