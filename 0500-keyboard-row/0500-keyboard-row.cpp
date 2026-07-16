class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string rows[] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

        unordered_map<char, int> mp;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < rows[i].length(); j++) {
                mp[rows[i][j]] = i;
            }
        }

        vector<string> ans;
        
        for (string word : words) {
            unordered_set<int> check;
            for (char c : word) {
                c = tolower(c);
                check.insert(mp[c]);
            }

            if (check.size() == 1) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};