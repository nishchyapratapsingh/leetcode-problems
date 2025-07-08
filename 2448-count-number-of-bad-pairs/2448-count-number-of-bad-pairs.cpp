class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long totalPairs = n * (n - 1) / 2;
        
        unordered_map<int, long long> freq;
        long long goodPairs = 0;
        
        for (int i = 0; i < n; ++i) {
            int key = nums[i] - i;
            goodPairs += freq[key];  // count how many times this key appeared before
            freq[key]++;
        }
        
        return totalPairs - goodPairs;
    }
};


