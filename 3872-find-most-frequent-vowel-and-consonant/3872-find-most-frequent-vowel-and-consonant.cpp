class Solution {
    bool isVowel(char c) {
        switch (c) {
            case 'a':
                return true;
            case 'e':
                return true;
            case 'i':
                return true;
            case 'o':
                return true;
            case 'u':
                return true;
        }
        return false;
    }
public:
    int maxFreqSum(string s) {
        int n=s.length();
        unordered_map<char, int>freq;
        for (int i=0; i<n; i++) {
            freq[s[i]]++;
        }
        int maxV=0;
        int maxC=0;
        for (int i=0; i<n; i++) {
            if (isVowel(s[i])) {
                maxV=max(maxV, freq[s[i]]);
            }
            else {
                maxC=max(maxC, freq[s[i]]);
            }
        }
        return maxV+maxC;
    }
};