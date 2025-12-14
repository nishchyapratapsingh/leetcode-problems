class Solution {
public:
    string frequencySort(string s) {
        vector<int> map(256, 0);
        for (char c : s) {
            map[c]++;
        }
        vector<int> sortedCounts = map;
        sort(sortedCounts.begin(), sortedCounts.end(), greater<int>());
        string res;
        for (int i = 0; i < 256; i++) {
            int currentMax = sortedCounts[i];
            if (currentMax == 0) break;
            for (int j = 0; j < 256; j++) {
                if (map[j] == currentMax) {
                    for (int k = 0; k < currentMax; k++) {
                        res += (char)j;
                    }
                    map[j] = 0;
                    break;
                }
            }
        }
        return res;
    }
};