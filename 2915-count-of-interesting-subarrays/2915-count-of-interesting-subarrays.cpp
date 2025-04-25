#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long count = 0;
        int prefix = 0;
        unordered_map<int, long long> freq;
        freq[0] = 1;  // Base case for prefix sum

        for (int num : nums) {
            if (num % modulo == k) {
                prefix++;
            }
            int mod_val = prefix % modulo;
            int target = (mod_val - k + modulo) % modulo;
            count += freq[target];
            freq[mod_val]++;
        }

        return count;
    }
};
