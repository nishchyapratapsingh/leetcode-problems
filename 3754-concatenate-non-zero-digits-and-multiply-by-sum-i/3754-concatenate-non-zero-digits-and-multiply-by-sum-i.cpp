class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;
        string num = to_string(n);
        string ansNum;

        long long sum = 0;

        for (char c : num) {
            if (c != '0') {
                ansNum.push_back(c);
                sum += c-'0';
            }
        }
         
        long long mult = stoi(ansNum);
        return sum*mult;
    }
};