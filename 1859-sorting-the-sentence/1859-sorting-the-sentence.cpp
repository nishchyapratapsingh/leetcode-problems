class Solution {
public:
    string sortSentence(string s) {
        stringstream ss(s);
        string word;
        vector<string> v(10); 

        while (ss >> word) {
            int n = word.size();
            int idx = word[n-1] - '0';
            v[idx] = word.substr(0, n-1);
        }

        string ans;
        for (int i = 1; i < v.size(); i++) {
            if (v[i].empty()) break;
            if (!ans.empty()) ans += " ";
            ans += v[i];
        }

        return ans;
    }
};