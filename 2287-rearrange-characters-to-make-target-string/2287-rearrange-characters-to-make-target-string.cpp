class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> srcFreq(26, 0);
        vector<int> tarFreq(26, 0);

        for (char c : s) {
            srcFreq[c-'a']++;
        }
        for (char c : target) {
            tarFreq[c-'a']++;
        }
        
        int maxInst = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (tarFreq[i] > 0) {
                maxInst = min(maxInst, srcFreq[i]/tarFreq[i]);
            }
        }

        return maxInst;
    }
};