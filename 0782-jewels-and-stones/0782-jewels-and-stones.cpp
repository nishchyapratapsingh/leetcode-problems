class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> freq;
        int ans=0;
        for (char stone: stones) {
            freq[stone]++;
        }
        for (char jewel: jewels) {
            ans+=freq[jewel];
        }
        return ans;
    }
};