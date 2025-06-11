class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        for (auto i: nums) {
            freqMap[i]++;
            if (freqMap[i]>1) {
                return i;
            }
        }
        return -1;
    }
};