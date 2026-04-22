class Solution {
private:
    bool f(string &str, string &dict) {
        int cnt = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] != dict[i]) cnt++;
        }

        return cnt <= 2;
    }
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for (string str: queries) {
            for (string dict: dictionary) {
                if (f(str, dict)) {
                    ans.push_back(str);
                    break;
                }
            }
        }

        return ans;
    }
};