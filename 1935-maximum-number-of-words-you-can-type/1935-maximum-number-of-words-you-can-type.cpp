class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int>freq(26);
        stringstream iss(text);
        string word;
        int count = 0;
        for (int i = 0; i < brokenLetters.length(); i++) {
            freq[brokenLetters[i] - 'a']++;
        }

        while (iss >> word) {
            bool flag = true;
            for (int i = 0; i < word.length(); i++) {
                if (freq[word[i] - 'a'] != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) count++;
        }

        return count;
    }
};