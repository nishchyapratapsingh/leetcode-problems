class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        unordered_map<string, int> cnt;
        for (string word: words) {
            string temp;
            for (char c: word) {
                temp += morse[c-'a'];
            }
            cnt[temp]++;
        }

        int distinct = 0;
        for (auto &it: cnt) {
            distinct++;
        }

        return distinct;
    }
};