class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int l=0;
        unordered_map<char, int> freqMap;
        int count=0;

        for (int r=0; r<n; r++) {
            freqMap[s[r]]++;
            while (freqMap['a']>0 && freqMap['b']>0 && freqMap['c']>0) {
                count += n-r;
                freqMap[s[l]]--;
                l++;
            }
        }
    
        return count;
    }
};