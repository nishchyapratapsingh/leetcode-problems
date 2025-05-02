class Solution {
    public:

        void backtrack(vector<string> &result, map<char, string> &phoneMap, string &digits, string currentCombination, int idx) {
            if (idx>=digits.length()) {
                result.push_back(currentCombination);
                return;
            }

            char digit = digits[idx];
            string value = phoneMap[digit];
            for (int i=0; i<value.length(); i++) {
                currentCombination.push_back(value[i]);
                backtrack(result, phoneMap, digits, currentCombination, idx+1);
                currentCombination.pop_back(); //backtrack
            }
        }

        vector<string> letterCombinations(string digits) {
            map<char, string> phoneMap = {
                {'0', ""},
                {'1', ""},
                {'2', "abc"},
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"}
            };  
            vector<string> result;  
            if (digits.empty()) return result;
            string currentCombination;
            backtrack(result, phoneMap, digits, currentCombination, 0);
            return result;
        }
    };