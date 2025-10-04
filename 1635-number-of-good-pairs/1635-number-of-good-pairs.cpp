class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num: nums) {
            freq[num]++;
        }
        int ans=0;
        for (auto &[num, count]: freq) {
            ans+= count*(count-1)/2;
        }
        return ans;
    }
};