class Solution {
private:
    void dfs(vector<string> &curPath, vector<vector<string>> &paths, string &beginWord, string &endWord, unordered_map<string, vector<string>> &parents) {
        curPath.push_back(endWord);

        if (beginWord == endWord) {  
            vector<string> t = curPath;
            reverse(t.begin(), t.end());
            paths.push_back(t);
            curPath.pop_back();
            return;
        }

        else {
            for (auto &p : parents[endWord]) {
                dfs(curPath, paths, beginWord, p, parents);
            }
        }

        curPath.pop_back();
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int l = beginWord.length();
        int n = wordList.size();

        unordered_map<string, vector<string>> parents;

        unordered_set<string> words;
        for (auto w : wordList) {
            words.insert(w);
        }

        queue<string> q;
        q.push(beginWord);
        words.erase(beginWord);

        while (!q.empty()) {
            int sz = q.size();
            unordered_set<string> visCurLevel;

            for (int p = 0; p < sz; p++) {
                string cur = q.front();
                q.pop();

                string w = cur;

                for (int i = 0; i < l; i++) {
                    char t = w[i];
                    for (int k = 0; k < 26; k++) {
                        if (k + 'a' == t) continue;
                        w[i] = k+'a';
                        if (words.count(w)) {
                            if (!visCurLevel.count(w)) q.push(w);
                            parents[w].push_back(cur);
                            visCurLevel.insert(w);
                        }
                    }
                    w[i] = t;
                }
            }

            if (parents.count(endWord)) break;

            for (auto &word : visCurLevel) {
                words.erase(word);
            }
        }

        if (!parents.count(endWord)) {
            return {};
        }

        vector<vector<string>> paths;
        vector<string> curPath;
        dfs(curPath, paths, beginWord, endWord, parents);
        
        return paths;
    }
};