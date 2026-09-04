class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int curstrt = nums[i];

            while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
                i++;
            }

            int curend = nums[i];

            if (curstrt == curend) {
                ans.push_back(to_string(curstrt));
            }
            else {
                string cur = to_string(curstrt);
                cur += "->";
                cur += to_string(curend);
                ans.push_back(cur);
            }
        }

        return ans;
    }
};