class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int mx = INT_MIN;
        for (int num : nums) {
            freq[num]++;
            mx = max(mx, freq[num]);
        }
        int cnt = 0;
        for(auto &it: freq) {
            if (it.second == mx) {
                cnt+=it.second;
            }
        }

        return cnt;

    }
};