class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, bool> valid;
        for (int i=0; i<allowed.length(); i++) {
            valid[allowed[i]] = true;
        }
        int cnt = 0;
        for (int i=0; i<words.size(); i++) {
            bool flag = true;
            for (int j=0; j<words[i].length(); j++) {
                if (valid.find(words[i][j])==valid.end()) {
                    flag = false;
                }
            }
            if (flag) cnt++;
        }
        return cnt;
    }
};