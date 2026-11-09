class Solution {
private:
    string format(int num) {
        string t = to_string(num);
        reverse(t.begin(), t.end());
        while (t.length() < 4) {
            t.push_back('0');
        }
        reverse(t.begin(), t.end());

        return t;
    }
public:
    int generateKey(int num1, int num2, int num3) {
        string a = format(num1);
        string b = format(num2);
        string c = format(num3);

        string key;

        for (int i = 0; i < 4; i++) {
            char ch = min(a[i], min(b[i], c[i]));
            key.push_back(ch);
        }

        return stoi(key);
    }
};