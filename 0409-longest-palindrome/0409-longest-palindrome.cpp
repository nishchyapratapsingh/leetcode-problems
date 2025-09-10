class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        int length = 0;
        bool hasOdd = false;
        for (auto &pair : freq) {
            length += (pair.second / 2) * 2;
            if (pair.second % 2 == 1)
                hasOdd = true;
        }
        if (hasOdd) length += 1;
        return length;
    }
};