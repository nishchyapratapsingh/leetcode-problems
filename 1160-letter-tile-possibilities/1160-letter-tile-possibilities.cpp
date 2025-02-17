class Solution {
public:
        int count = 0;

    void backtrack(vector<int>& freq) {
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                count++;
                freq[i]--;  // Choose the letter
                backtrack(freq);  // Recur with remaining letters
                freq[i]++;  // Backtrack (undo the choice)
            }
        }
    }

    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);
        
        // Count frequency of each letter
        for (char c : tiles) freq[c - 'A']++;

        // Start backtracking
        backtrack(freq);

        return count;
    
    }
};