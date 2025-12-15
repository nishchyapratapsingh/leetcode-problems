class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int beauty = 0;
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                int freq[26] = {0};
                for (int k = i; k <= j; k++) {
                    freq[s[k]-'a']++;
                }
                int mini = INT_MAX;
                int maxi = INT_MIN;
                for (int l = 0; l < 26; l++) {
                    if(freq[l] > 0) {
                        mini = min(freq[l], mini);
                        maxi = max(freq[l], maxi);
                    }
                }
                beauty += (maxi - mini);
            }
        }
        return beauty;
    }
};