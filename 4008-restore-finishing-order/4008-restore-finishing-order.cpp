class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_map<int, bool> id_table;
        for (int id : friends) {
            id_table[id] = true;
        }
        vector<int> ans;
        for (int id : order) {
            if (id_table.count(id)) {
                ans.push_back(id);
            }
        }
        return ans;
    }
};