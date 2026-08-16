class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        if (n % 2 != 0) return 0;

        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        for (int num : nums) {
            if (freq[num] % 2 == 1) {
                return 0;
            }
        }

        return 1;
    }
};