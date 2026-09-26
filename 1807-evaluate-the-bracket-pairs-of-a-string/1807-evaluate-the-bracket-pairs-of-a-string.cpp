class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto &k : knowledge) {
            mp[k[0]] = k[1];
        }

        int n = s.length();
        string ans;

        int i = 0;
        while (i < n) {
            if (s[i] == '(') {
                int j = i;
                while (j < n && s[j] != ')') j++;

                string t = s.substr(i+1, j-i-1);

                if (mp.count(t)) {
                    ans += mp[t];
                }
                else {
                    ans += '?';
                }

                i = j+1;
            }

            else {
                ans += s[i];
                i++;
            }
        }

        return ans;
    }
};