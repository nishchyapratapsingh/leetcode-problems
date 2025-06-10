class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freqMap;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int n=s.length();
        for (int i=0; i<n; i++) {
            freqMap[s[i]]++;
        }
        for (auto& pair : freqMap) {
            int freq = pair.second;
            if (freq % 2 != 0) {
                maxi = max(maxi, freq);
            } else {
                mini = min(mini, freq);
            }
        }
        if (mini == INT_MAX || maxi == INT_MIN) return 0;
        return maxi-mini;
    }
};