class Solution {
    int helper (vector<int>& cost, vector<int>& memo, int idx) {
        if (idx==1) {
            return 0;
        }
        if (idx==0) {
            return 0;
        }
        if (memo[idx]>=0) {
            return memo[idx];
        }

        int res = min(helper(cost,memo, idx-1)+cost[idx-1], helper(cost,memo, idx-2)+cost[idx-2]);
        memo[idx] = res;
        return res;

    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size()+1, -1);
        return helper(cost, memo, cost.size());
    }
};