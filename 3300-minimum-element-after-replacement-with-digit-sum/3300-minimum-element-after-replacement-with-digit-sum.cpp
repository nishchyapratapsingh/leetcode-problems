class Solution {
public:
    int minElement(vector<int>& nums) {
        int mn = INT_MAX;
        for (int num: nums) {
            string str = to_string(num);
            int sum = 0;

            for (char c: str) {
                sum += (c - '0');
            }

            mn = min(mn, sum);
        }

        return mn;
    }
};