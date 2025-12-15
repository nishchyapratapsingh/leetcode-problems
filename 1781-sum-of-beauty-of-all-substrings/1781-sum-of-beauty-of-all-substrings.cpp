class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int beauty = 0;
        for (int i = 0; i < n; i++) {
            int freq[26] = {0};
            for (int j = i; j < n; j++) {
                freq[s[j]-'a']++;
                int mini = INT_MAX;
                int maxi = INT_MIN;
                for (int k = 0; k < 26; k++) {
                    if(freq[k] > 0) {
                        mini = min(freq[k], mini);
                        maxi = max(freq[k], maxi);
                    }
                }
                beauty += (maxi - mini);
            }
        }
        return beauty;
    }
};