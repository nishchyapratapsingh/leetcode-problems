class Solution {
public:
    string convertDateToBinary(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        string y = toBinary(year);
        string m = toBinary(month);
        string d = toBinary(day);

        return y + "-" + m + "-" + d;
    }

private:
    string toBinary(int n) {
        string res;
        while (n > 0) {
            res = char('0' + (n % 2)) + res;
            n /= 2;
        }
        return res.empty() ? "0" : res;
    }
};
