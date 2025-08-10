class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n<=1) return 0;
        int prev1=0; //i-1
        int prev2=0; //i-2
        for (int i=2; i<=n; ++i) {
            int curr = min(prev1 + cost[i-1], prev2 + cost[i-2]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};