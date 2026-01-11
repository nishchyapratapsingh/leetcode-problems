class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string word;
        vector<string> words;
        while (iss >> word) {
            int i = 0;
            int j = word.length()-1;
            while (i < j) {
                char temp = word[i];
                word[i] = word[j];
                word[j] = temp;
                i++;
                j--;
            }
            words.push_back(word);
        }
        string res;
        int n = s.length();
        int wordIdx = 0;
        for (int i=0; i<n; i++) {
            while (i<n && s[i] == ' ') {
                i++;
            }
            res += words[wordIdx++];
            if (wordIdx < words.size()) res.push_back(' ');
            while (i<n && s[i] != ' ') {
                i++;
            }
        }
        return res;
    }
};