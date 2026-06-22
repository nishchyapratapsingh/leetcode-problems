class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26);

        string balloon = "balloon";

        for (char c : text) {
            freq[c-'a']++;
        }

        freq['l' - 'a'] /= 2;
        freq['o' - 'a'] /= 2;
        int maxInst = INT_MAX;
        for (char c : balloon) {
            maxInst = min(freq[c-'a'], maxInst);
        }

        return maxInst;
    }
};