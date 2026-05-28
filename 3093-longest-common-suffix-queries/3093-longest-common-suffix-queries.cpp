class Solution {
public:

    struct TrieNode {
        int child[26];
        int idx;

        TrieNode() {
            for (int i = 0; i < 26; i++) {
                child[i] = -1;
            }
            idx = -1;
        }
    };

    vector<TrieNode> trie = vector<TrieNode>(1);

    vector<string>* wordsPtr;

    bool better(int a, int b) {

        if (b == -1)
            return true;

        vector<string>& words = *wordsPtr;

        if (words[a].size() < words[b].size())
            return true;

        if (words[a].size() == words[b].size() && a < b)
            return true;

        return false;
    }

    void insert(string s, int idx) {

        reverse(s.begin(), s.end());

        int node = 0;

        if (better(idx, trie[node].idx)) {
            trie[node].idx = idx;
        }

        for (char c : s) {

            int x = c - 'a';

            if (trie[node].child[x] == -1) {

                trie[node].child[x] = trie.size();

                trie.push_back(TrieNode());
            }

            node = trie[node].child[x];

            if (better(idx, trie[node].idx)) {
                trie[node].idx = idx;
            }
        }
    }

    int search(string q) {

        reverse(q.begin(), q.end());

        int node = 0;

        for (char c : q) {

            int x = c - 'a';

            if (trie[node].child[x] == -1)
                break;

            node = trie[node].child[x];
        }

        return trie[node].idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        wordsPtr = &wordsContainer;

        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer[i], i);
        }

        vector<int> ans;

        for (string& q : wordsQuery) {
            ans.push_back(search(q));
        }

        return ans;
    }
};