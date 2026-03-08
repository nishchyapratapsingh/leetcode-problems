class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {

        int cnt = 0;
        
        for (auto array: items) {
            if (
                (ruleKey == "type" && ruleValue ==  array[0]) ||
                (ruleKey == "color" && ruleValue == array[1]) ||
                (ruleKey == "name" && ruleValue == array[2])
            )
            cnt++;
        }

        return cnt;
    }
};