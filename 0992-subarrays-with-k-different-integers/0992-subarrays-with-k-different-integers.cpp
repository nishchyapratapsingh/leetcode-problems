class Solution {
    int f(vector<int> &arr, int k) {
        if (k == 0) return 0;
        
        unordered_map<int, int> freq;
        int n = arr.size();
        int l = 0;
        int ans = 0;
        
        for (int r = 0; r < n; r++) {
            freq[arr[r]]++;
            
            while (freq.size() > k) {
                freq[arr[l]]--;
                if (freq[arr[l]] == 0) freq.erase(arr[l]);
                l++;
            }
            
            ans += r-l+1;
        }
        
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k-1);
    }
};