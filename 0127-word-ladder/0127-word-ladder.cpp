class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int l = beginWord.length();
        int n = wordList.size();

        unordered_map<string, int> dist;

        unordered_set<string> words;
        for (auto w : wordList) {
            words.insert(w);
        }

        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 0;
        words.erase(beginWord);

        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            if (cur == endWord) break;

            string w = cur;

            for (int i = 0; i < l; i++) {
                char t = w[i];
                for (int k = 0; k < 26; k++) {
                    w[i] = k+'a';
                    if (words.count(w)) {
                        words.erase(w);
                        q.push(w);
                        dist[w] = dist[cur]+1;
                    }
                }
                w[i] = t;
            }
        }

        return dist.count(endWord) ? dist[endWord] + 1 : 0;
    }
};