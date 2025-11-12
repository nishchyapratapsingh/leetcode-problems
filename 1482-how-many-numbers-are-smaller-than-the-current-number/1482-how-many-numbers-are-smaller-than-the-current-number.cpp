class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int i=0;
        int n = nums.size();
        unordered_map<int, int> table;
        while (i<n) {
            if (i>0 && sorted[i] == sorted[i-1]) {
                i++;
                continue;
            }
            table[sorted[i]] = i;
            i++;
        }
        vector<int> ans;
        for (int num: nums) {
            ans.push_back(table[num]);
        }
        return ans;
    }
};