class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.length();
        if (num[n-1]%2!=0) return num;
        for (int j=n-1; j>=0; j--) {
            if (num[j]%2 != 0) {
                return num.substr(0, j+1);
            }
        }
        return "";
    }
};