class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int l = beginWord.length();
        int n = wordList.size();

        int dist = 0;

        unordered_set<string> words;
        for (auto w : wordList) {
            words.insert(w);
        }

        queue<string> q;
        q.push(beginWord);
        words.erase(beginWord);

        while (!q.empty()) {
            int sz = q.size();
            dist++;

            while (sz--) {
                string cur = q.front();
                q.pop();

                if (cur == endWord) return dist;

                string w = cur;

                for (int i = 0; i < l; i++) {
                    char t = w[i];
                    for (int k = 0; k < 26; k++) {
                        w[i] = k+'a';
                        if (words.count(w)) {
                            words.erase(w);
                            q.push(w);
                        }
                    }
                    w[i] = t;
                }
            }
        }

        return 0;
    }
};