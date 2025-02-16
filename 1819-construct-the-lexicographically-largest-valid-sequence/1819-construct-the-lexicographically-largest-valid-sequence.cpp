class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        int size = 2 * n - 1;  // The total size of the array
        vector<int> res(size, 0);  // Initialize with 0s
        vector<bool> used(n + 1, false);  // Track used numbers
        
        // Backtracking function
        function<bool(int)> backtrack = [&](int idx) {
            if (idx == size) return true;  // If we filled the array, return success
            
            if (res[idx] != 0) return backtrack(idx + 1); // Skip if already filled
            
            for (int num = n; num >= 1; num--) {  // Try from largest to smallest
                if (used[num]) continue; // Skip if already used
                
                int secondIdx = (num == 1) ? idx : idx + num; // Position for second occurrence
                
                if (num == 1 || (secondIdx < size && res[secondIdx] == 0)) {
                    // Place the number
                    res[idx] = num;
                    if (num > 1) res[secondIdx] = num;
                    used[num] = true;

                    if (backtrack(idx + 1)) return true;  // Recur to next position
                    
                    // Undo changes (backtrack)
                    res[idx] = 0;
                    if (num > 1) res[secondIdx] = 0;
                    used[num] = false;
                }
            }
            return false;  // No valid placement found
        };
        
        backtrack(0);
        return res;
    
        
    }
};