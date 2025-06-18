class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> freqMap;
        int n = fruits.size();
        int maxFruits = 0;
        int l=0;
        int basket=0;

        for (int r=0; r<n; r++) {
            if (freqMap[fruits[r]]==0) basket++;
            freqMap[fruits[r]]++;
            
            while (basket>2) {
                freqMap[fruits[l]]--;
                if (freqMap[fruits[l]]==0) basket--;
                l++;
            }
            maxFruits = max(maxFruits, r-l+1);
        }
        return maxFruits;
    }
};