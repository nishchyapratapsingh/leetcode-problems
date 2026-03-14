class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singleSum = 0, doubleSum = 0;

        for (int x : nums) {
            if (x < 10) singleSum += x;
            else doubleSum += x;
        }

        if (singleSum > doubleSum) return true;
        if (doubleSum > singleSum) return true;

        return false;
    }
};