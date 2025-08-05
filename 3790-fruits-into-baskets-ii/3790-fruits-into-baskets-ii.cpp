class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int m = baskets.size();
        int ans = n;
        unordered_map<int, int> used;

        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (!used[j] && fruits[i] <= baskets[j]) {
                    ans--;
                    used[j] = 1;
                    break;
                }
            }
        }

        return ans;
    }
};