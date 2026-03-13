class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int num: nums) {
            string temp = to_string(num);
            for (int i = 0; i < temp.length(); i++) {
                ans.push_back(temp[i] - '0');
            }
        }

        return ans;
    }
};