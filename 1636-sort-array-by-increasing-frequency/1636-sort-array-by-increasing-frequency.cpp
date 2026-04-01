class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int num: nums) {
            map[num]++;
        }

        vector<pair<int, int>> v(map.begin(), map.end());
        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.second == b.second) {
                return a.first > b.first;
            }
            return a.second < b.second;
        });

        vector<int> ans;
        for (auto &p: v) {
            int n = p.second;
            while (n--){
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};