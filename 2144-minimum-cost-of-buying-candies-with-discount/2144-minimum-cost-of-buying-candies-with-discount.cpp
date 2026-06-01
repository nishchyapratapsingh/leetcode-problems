class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int ans = 0;
        int n = cost.size();
        int t = 0;
        for (int i = 0; i < n; i++) {
            if (t < 2) {
                ans += cost[i];
                t++;
            }
            else t = 0;
        }

        return ans;
    }
};