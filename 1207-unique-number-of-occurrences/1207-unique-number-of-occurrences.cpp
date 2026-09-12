class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;

        for (int num : arr) {
            freq[num]++;
        }

        int cnt = 0;
        unordered_set<int> s;
        for (auto &it : freq) {
            s.insert(it.second);
            cnt++;
        }

        return s.size() == cnt;
    }
};